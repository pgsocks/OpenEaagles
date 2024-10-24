add_library(interop_dis
	EmissionPduHandler.cpp
	factory.cpp
	NetIO.cpp
	NetIO_entity_state.cpp
	NetIO_munition_detonation.cpp
	NetIO_weapon_fire.cpp
	Nib.cpp
	Nib_entity_state.cpp
	Nib_iff.cpp
	Nib_munition_detonation.cpp
	Nib_weapon_fire.cpp
	Ntm.cpp
)

target_link_libraries (
	interop_dis
	PRIVATE
	base
)

target_include_directories (
	interop_dis
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
