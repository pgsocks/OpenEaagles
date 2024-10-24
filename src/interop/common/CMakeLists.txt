add_library(interop_common
	NetIO.cpp
	Nib.cpp
	Ntm.cpp
)

target_link_libraries (
	interop_common
	PRIVATE
	simulation
	base
	models
)
