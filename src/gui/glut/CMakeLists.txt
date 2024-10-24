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
