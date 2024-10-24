add_library(gui_glut
	factory.cpp
	GlutDisplay.cpp
	Shapes3D.cpp
)

target_link_libraries (
	gui_glut
	PRIVATE
	base
	graphics
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
