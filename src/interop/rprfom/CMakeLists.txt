add_library(interop_rprfom
	factory.cpp
	NetIO.cpp
	NetIO_entity_state.cpp
	NetIO_munition_detonation.cpp
	NetIO_weapon_fire.cpp
	Nib.cpp
	Nib_entity_state.cpp
	Nib_munition_detonation.cpp
	Nib_weapon_fire.cpp
	Ntm.cpp
	RprFom.cpp
)

target_include_directories (
	interop_rprfom
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

install (
	TARGETS interop_rprfom
)

install (
	DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
