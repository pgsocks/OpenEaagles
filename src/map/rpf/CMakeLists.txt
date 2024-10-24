add_library(map_rpf
	CadrgClut.cpp
	CadrgFile.cpp
	CadrgFrame.cpp
	CadrgFrameEntry.cpp
	CadrgMap.cpp
	CadrgTocEntry.cpp
	factory.cpp
	MapDrawer.cpp
	TexturePager.cpp
	TextureTable.cpp
	map_utils.cpp
)

target_include_directories (
	gui_glut
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
