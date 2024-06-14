#include "stdafx.h"
DWORD featureWeaponVehShootLastTime = 0;
int Features::Online::selectedPlayer = 0;
void Features::Online::TeleportToPlayer(Player player) {

	Entity handle;
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(player), false);
	PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
	ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
}

char *call1o;
char *call2o;
char *nameo;
Ped PTLoopPed;

char *call1s;
char *call2s;
char *names;

bool Features::fastrun = false;
bool Features::fastswim = false;
void Features::SwimFast()
{
	if (!fastswim)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 1);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 2.5);
	}
}
void shootVehBullet(char* bullet) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = IsKeyPressed(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY(bullet);
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}
int Features::attachobj[100];
int Features::nuattach = 1;
void Features::attachobjects2(char* object)
{
	bool custom = false;
	int hash = 0;
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(Features::Online::selectedPlayer), true);
	hash = GAMEPLAY::GET_HASH_KEY(object);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
	{
		if (STREAMING::IS_MODEL_VALID(hash))
		{
			STREAMING::REQUEST_MODEL(hash);
			if (STREAMING::HAS_MODEL_LOADED(hash))
			{
				Features::attachobj[Features::nuattach] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Features::attachobj[Features::nuattach]))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Features::attachobj[Features::nuattach], PLAYER::GET_PLAYER_PED(Features::Online::selectedPlayer), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
					nuattach++;
					if (nuattach >= 101) { nuattach = 1; }
				}
			}
		}
	}
}

void PTFXCALL(char *call1, char *call2, char *name)
{
	call1o = call1;
	call2o = call2;
	nameo = name;

	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

}
bool Features::controler = true;
bool Features::infammo = false;
bool Features::freezed[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::Freezer(Player target) {
	Ped vic = PLAYER::GET_PLAYER_PED(target);
	AI::CLEAR_PED_TASKS_IMMEDIATELY(vic);
	AI::CLEAR_PED_TASKS(vic);
	AI::CLEAR_PED_SECONDARY_TASK(vic);
}
bool Features::redLaserCar = false;
void Features::redLasers() {
	shootVehBullet("VEHICLE_WEAPON_ENEMY_LASER");
}

bool Features::tankCar = false;
void Features::shootTankShell() {
	shootVehBullet("VEHICLE_WEAPON_TANK");
}

bool Features::carFireworks = false;
void Features::shootFireworks() {
	shootVehBullet("WEAPON_FIREWORK");
}

bool Features::carRPG = false;
void Features::shootRPGCar() {
	shootVehBullet("WEAPON_VEHICLE_ROCKET");
}
void Features::RunFast()
{
	if (!fastrun)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 2.5);
	}
}
bool Features::flybool = false;
void Features::playerflyer() {

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	if (GetAsyncKeyState(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		float xVec = fivef * sin(degToRad(heading)) * -1.0f;
		float yVec = fivef * cos(degToRad(heading));
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.x -= xVec, pos.y -= yVec;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		float xVec = fivef * sin(degToRad(heading)) * -1.0f;
		float yVec = fivef * cos(degToRad(heading));
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.x += xVec, pos.y += yVec;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_A) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading + 0.5f);
	}
	if (GetAsyncKeyState(VK_KEY_D) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading - 0.5f);
	}
	if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb)) {
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.z -= 0.5;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendLb)) {
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.z += 0.5;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
}
bool Features::ClownLoop = false;
bool Features::fireworkloop = false;
bool Features::alien1 = false;
bool Features::alien2 = false;
bool Features::electric = false;
bool Features::watereffect = false;
bool Features::smokeeffect = false;
bool Features::bloodeffect = false;
bool Features::moneyeffect = false;
