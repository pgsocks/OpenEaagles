add_library(models
	dynamics/AerodynamicsModel.cpp
	dynamics/DynamicsModel.cpp
	dynamics/JSBSimModel.cpp
	dynamics/LaeroModel.cpp
	dynamics/RacModel.cpp
	dynamics/SpaceDynamicsModel.cpp
	environment/AbstractAtmosphere.cpp
	environment/IrAtmosphere.cpp
	environment/IrAtmosphere1.cpp
	navigation/Bullseye.cpp
	navigation/Gps.cpp
	navigation/Ins.cpp
	navigation/Navigation.cpp
	navigation/Route.cpp
	navigation/Steerpoint.cpp
	player/Aam.cpp
	player/AbstractWeapon.cpp
	player/Agm.cpp
	player/AirVehicle.cpp
	player/Bomb.cpp
	player/Buildings.cpp
	player/Bullet.cpp
	player/Effects.cpp
	player/GroundVehicle.cpp
	player/LifeForms.cpp
	player/Missile.cpp
	player/Player.cpp
	player/Sam.cpp
	player/SamVehicles.cpp
	player/Ships.cpp
	player/SpaceVehicle.cpp
	sensor/Gmti.cpp
	sensor/Stt.cpp
	sensor/Tws.cpp
	system/AngleOnlyTrackManager.cpp
	system/Antenna.cpp
	system/Autopilot.cpp
	system/AvionicsPod.cpp
	system/CollisionDetect.cpp
	system/Datalink.cpp
	system/ExternalStore.cpp
	system/FuelTank.cpp
	system/Gimbal.cpp
	system/Guns.cpp
	system/Iff.cpp
	system/IrSeeker.cpp
	system/IrSensor.cpp
	system/IrSystem.cpp
	system/Jammer.cpp
	system/MergingIrSensor.cpp
	system/OnboardComputer.cpp
	system/Pilot.cpp
	system/Radar.cpp
	system/Radio.cpp
	system/RfSensor.cpp
	system/RfSystem.cpp
	system/Rwr.cpp
	system/Sar.cpp
	system/ScanGimbal.cpp
	system/StabilizingGimbal.cpp
	system/Stores.cpp
	system/StoresMgr.cpp
	system/System.cpp
	system/TrackManager.cpp
	Actions.cpp
	AircraftIrSignature.cpp
	Designator.cpp
	Emission.cpp
	Image.cpp
	IrQueryMsg.cpp
	IrShapes.cpp
	IrSignature.cpp
	Message.cpp
	MultiActorAgent.cpp
	SensorMsg.cpp
	Signatures.cpp
	SimAgent.cpp
	SimAgent.cpp
	SynchronizedState.cpp
	TargetData.cpp
	Tdb.cpp
	Track.cpp
	WorldModel.cpp
	factory.cpp
)

target_include_directories (
	models
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

install (
	DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
