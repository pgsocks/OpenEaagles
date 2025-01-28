add_library(terrain
	STATIC
	ded/DedFile.cpp
	dted/DtedFile.cpp
	srtm/SrtmHgtFile.cpp
	DataFile.cpp
	factory.cpp
	QuadMap.cpp
	Terrain.cpp
)

target_link_libraries (
	terrain
	PUBLIC
	base
)

target_include_directories (
	terrain
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
