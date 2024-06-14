#pragma once

namespace Features {

	extern float test1;
	extern float test2;
	extern float test3;

	extern bool ClownLoop;
	extern bool fireworkloop;
	extern bool alien1;
	extern bool alien2;
	extern bool electric;
	extern bool watereffect;
	extern bool smokeeffect;
	extern bool bloodeffect;
	extern bool moneyeffect;
	extern bool knibbleknatzli;

	extern bool moneyToBank;

	extern bool DropAll2;
	void dropAll2();
	extern bool excludeSelf;

	extern bool DropAll;
	void dropAll();

	extern bool WeaponF1rework;
	void featureWeaponFirework();

	extern bool loggedIn;
	extern bool loginAttempted;
	extern std::vector<char*> username;
	extern std::vector<char*> password;
	extern char* Status;
	extern std::string connstring;
	void login();
	void typeInUser();
	void typeInPass();
	void enterInfo();
	void tpToW();
	extern bool tpToWayBool;
	extern bool sp_vehicle_bypass;
	void oppp(bool toggle);

	//DROP MODELS
	extern bool alienegg;
	extern bool handBag;
	extern bool polyBag;
	extern bool goldBar;
	extern bool dildo;
	extern bool documents;
	extern bool bucket;


	void UpdateLoop();
	void PlaceObjectByHash(Hash hash, float x, float y, float z, float pitch, float roll, float yaw, float heading, int id);
	void TPtoWaypoint();

	void riskyOptins();

	extern int TimePD;

	//Ped getLocalPlayerPed();

	extern int Levels[8000];

	extern int ExploCh;
	extern int WaterIntense;

	void Freezer(Player target);
	extern bool freezed[35];

	extern bool expmeel;
	extern bool tpgun;
	extern bool pedgun;
	extern bool fireammo;
	extern bool expammo;
	extern bool rbgun;
	extern bool flyToggle;
	extern bool OffTheRadarBool;

	//void spawn_vehicle(char* toSpawn);
	//void spawn_vehicle2(char* toSpawn, Vector3 ourCoords);

	void BypassOnlineVehicleKick(Vehicle vehicle);
	extern bool Forcefield;
	void Expmeels();
	void tpGuns();
	void Pedguns();
	void Fireammos();
	void Expammos();
	void OffTheRadar();
	void RBGuner();
	void flyingCar1();

	extern bool redLaserCar;
	void redLasers();

	extern bool greenLaserCar;
	void greenLasers();

	extern bool tankCar;
	void shootTankShell();

	extern bool carFireworks;
	void shootFireworks();

	extern bool carRPG;
	void shootRPGCar();

	extern bool carSnow;
	void shootCarSnow();

	extern bool flareCar;
	void shootFlareCar();

	void RequestControl(DWORD entity);

	extern int number;

	Vehicle SpawnVehicle(char* modelg, Vector3 coords, bool tpinto, float heading);

	bool cstrcmp(const char* s1, const char* s2);

	extern bool Neverwanted;
	void NeverGetWanted();
	void RequestControlOfid(DWORD netid);

	extern bool rainbowmenu;
	void Rainbowmenu();

	extern bool RPLoop;
	extern int RPLoopDelay;
	void rpLoop();


	extern bool pausetime;
	void pauseTime(bool toggle);


	extern bool fastrun;
	extern bool fastswim;
	void RunFast();
	void SwimFast();
	extern bool osk;
	extern bool superman;
	void OSKR();
	void SupermanT();
	extern int HornBoostSpeed;
	void OffRadar();
	extern bool OffRadarB00l;

	void SetRank(int rpvalue);
	extern bool shootcash;
	extern bool AttachDetach[35];

	extern bool playerGodMode;
	void GodMode(bool toggle);

	extern bool playersuperjump;
	void SuperJump(bool toggle);

	extern bool playerinvisibility;
	void Invisibility(bool toggle);


	extern bool gameCamZoom;
	extern float gameCamZoomInt;
	void zoomCam();

	extern bool playerfireloop[35];
	void FireLoop(Player target);

	extern bool playerwaterloop[35];
	void WaterLoop(Player target);

	extern bool playernoragdoll;
	void NoRagdoll(bool toggle);

	

	extern int attachobj[100];
	extern int nuattach;
	void attachobjects2(char* object);

	void DeleteEntity(int Handle);


	extern bool boostbool;
	void carboost();

	extern bool bikeNoFall;
	void nofallbike();

	extern bool vehJumps;
	void vehicleJumps();

	extern bool dowbool;
	void DriveOnWater();

	extern bool fcbool;
	void FlyingCarLoop();

	extern bool infammo;
	void noreloadv();


	extern bool rlbool;
	void HasPaintLoop();

	extern bool bulletProof;
	void bulletP();

	extern int TimePD;
	extern int TimePD1;
	extern int TimePD2;
	extern int TimePD3;
	extern int TimePD4;
	extern int TimePD5;
	extern int TimePD6;
	extern int TimePD7;
	extern int TimePD8;
	void LoadPlayerInfo(char* playerName, Player p);
	extern int l;
	extern int l1;
	extern int l2;
	extern int l3;
	extern int l4;
	extern int l5;
	extern int l6;

	void teleporttocoords(Player player, Vector3 target);
	void teleportallcoords(Vector3 target);
	void ramWithVeh(Player target);
	void doAnimation(char* anim, char* animid);

	extern bool flybool;
	void playerflyer();
	extern bool controler;


	void RequestControlOfid(Entity netid);

	void RequestingControl(Entity e);
	void playAnimationPlayer(Player player, bool loop, char * dict, char * anim);

	extern bool cargodmodebool;
	void cargodmode();
	extern bool enginealwaysonbool;
	void enginealwayson();
	void flipup();
	void maxvehicle();

	extern bool fuckedhandling[32];
	void fuckhandling(Player player);

	extern bool camshaker[32];
	void shakecam(Player target);

	extern bool exploder[32];
	void explodeloop(Player target);

	extern bool nightvisionbool;
	void nightvision();
	void deposit(long amount);
	void withdraw(long amount);

	void animation(char* anim, char* dict);
	void clearanim();

	extern bool esper;
	void esp(Player target);
	extern bool nameEsper;
	void nameEsp(Player target);

	extern bool superrun;
	void superrRun();

	extern bool RPGGun;
	void RPGGunner();

	void teleportallcoordsns(Vector3 target);

	void SpoofName(std::string name);

	//void givemoney(int player, int amount);

	//void clearbala();

	void TinyPlayer(bool toggle);
	void changeplate();
	void trapcage(Ped ped);
	void trapall();

	extern bool betiny;
	extern bool spectate[32];
	void specter(Player target);

	extern float accelerationfloat;
	extern float brakeforcefloat;
	extern float tractionfloat;
	extern float deformfloat;
	extern float upshiftfloat;
	extern float suspensionfloat;
	void updatePhysics();
	void acceleration();
	void brakeforce();
	void traction();
	void deform();
	void upshift();
	void suspension();
	//extern bool vehiclegravitybool;
	//void vehiclegravity();
	extern bool killpedsbool;
	void killpeds();

	void PTFXCALL(char *call1, char *call2, char *name);
	void PTFXCALLO(char *call1, char *call2, char *name, Ped target);

	extern bool PTLoopedO[35];
	void PTLopperO(Player target);

	extern bool PTLooped;
	void PTLopper();
	void StealthRP(Player player);
	//void StealthDropende(Player player);
	extern int reamount;
	//extern bool StealthLooptoggler[35];
	//void StealthLoopre(Player player);
	extern std::string name;
	extern std::string pw;
	//extern bool StealthLooptogglerall;
	//void StealthLoopreall();

	extern bool rapidfirer;
	void rapidmaker();

	extern bool explodepedsbool;
	void explodepeds();
	extern bool explodenearbyvehiclesbool;
	void explodenearbyvehicles();
	extern bool deletenearbyvehiclesbool;
	void deletenearbyvehicles();

	extern int amount;
	extern int bulletType;
	extern bool SnowGun;
	void SnowGunVoid();
	extern bool C4Gun;
	void c4Gun();
	extern bool FlareGun;
	void flareGun();
	extern bool MolotovGun;
	void molotovGun();

	extern bool customImpactBool;
	void CustomImpact();

	extern int impactExplosion;

	extern int DropAmount;
	extern int DropHeight;
	extern int DropDelay;
	extern int Bags;
	extern Hash bagHash;
	extern int amount2;
	extern int amount3;
	extern bool moneyGun;
	void dollarGun();
	extern bool banked;
	extern bool giver;
	void StealthDropinte();
	extern bool DeleteLastOnSpawn;
	void CrashPlayer();

	extern bool spawnincar;
	extern bool spawnmaxed;
	extern bool FrWrkT;
	void FrWrk();
	void spawn_vehicle(std::string vehicle);
	void give_vehicle(char* vehicle);
	void giveAll_vehicle(char* vehicle);
	void OffRadarLester();
	extern bool OffRadarLesterToggle;

	//extern bool nStealthLooptogglerall;
	//void nStealthLoopreall();
	//extern bool nStealthLooptoggler[35];
	//void nStealthLoopre(Player player);

	//new
	void riskyOptins();

	extern bool PTLooped;
	void StealthRP(Player player);
	void StealthDropende(Player player);
	extern int reamount;
	extern bool StealthLooptoggler[35];
	void StealthLoopre(Player player);
	extern std::string name;
	extern std::string pw;
	extern bool StealthLooptogglerall;
	void StealthLoopreall();
	void StealthDropintee();

	extern bool StealthLooptoggle;
	void StealthLoop();

	void deposit(long amount);
	void withdraw(long amount);

	extern bool rapidfirer;
	void rapidmaker();

	extern bool explodepedsbool;
	void explodepeds();
	extern bool explodenearbyvehiclesbool;
	void explodenearbyvehicles();
	extern bool deletenearbyvehiclesbool;
	void deletenearbyvehicles();

	extern bool is_file_exist(const char *fileName);
	extern bool isSteam;

	extern int StelffAmount;

	extern bool firegun;
	void FireG0ns();

	extern char* CurrentPTFX;
	extern char* CurrentPTFX1;
	extern char* CurrentPTFX2;
	extern int amount;
	extern int amount2;
	extern int amount3;
	extern bool banked;
	extern bool toBank;
	extern bool ClownLoop;
	extern bool fireworkloop;
	extern bool alien1;
	extern bool alien2;
	extern bool electric;
	extern bool watereffect;
	extern bool smokeeffect;
	extern bool bloodeffect;
	extern int attachobj[100];
	extern int nuattach;
	void attachobjects2(char* object);
	extern bool moneyeffect;
	extern bool redLaserCar;
	void redLasers();

	extern bool greenLaserCar;
	void greenLasers();

	extern bool tankCar;
	void shootTankShell();

	extern bool carFireworks;
	void shootFireworks();

	extern bool carRPG;
	void shootRPGCar();

	extern bool infammo;
	void noreloadv();
	extern bool knibbleknatzli;
	void PTFXCALL(char *call1, char *call2, char *name);
	void PTFXCALLO(char *call1, char *call2, char *name, Ped target);

	extern bool spawnincar;
	extern bool spawnmaxed;
	extern bool PTFXGunToggle;
	void PTFXGun();
	void PTFXGUNCALL(char *call1, char *call2, char *name);
	extern bool delGun;
	void DeleteGun();

	extern bool AntiPickup;
	void SpoofName(std::string name);

	//extern bool nStealthLooptogglerall;
	//void nStealthLoopreall();
	//extern bool nStealthLooptoggler[35];
	//void nStealthLoopre(Player player);
	//till here
	extern bool fastrun;
	extern bool fastswim;
	void RunFast();
	void SwimFast();
	extern bool flybool;
	void playerflyer();
	extern bool controler;

	namespace Online {
		extern int selectedPlayer;
		void TeleportToPlayer(Player player);
	}
}



