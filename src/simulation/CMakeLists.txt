add_library(simulation
	AbstractDataRecorder.cpp
	AbstractNetIO.cpp
	AbstractNib.cpp
	AbstractOtw.cpp
	AbstractPlayer.cpp
	AbstractRecorderComponent.cpp
	SimBgThread.cpp
	SimTcThread.cpp
	Simulation.cpp
	Station.cpp
	StationBgThread.cpp
	StationNetThread.cpp
	StationTcThread.cpp
	factory.cpp
)

target_link_libraries (
	simulation
	PRIVATE
	base
)

target_include_directories (
	simulation
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
