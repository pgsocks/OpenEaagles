add_library(dafif
	Airport.cpp
	AirportLoader.cpp
	Record.cpp
	Database.cpp
	factory.cpp
	Ils.cpp
	Navaid.cpp
	NavaidLoader.cpp
	Runway.cpp
	Waypoint.cpp
	WaypointLoader.cpp
)

target_link_libraries (
	dafif
	PRIVATE
	base
)

target_include_directories (
	dafif
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
