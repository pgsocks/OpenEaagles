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

target_include_directories (
	interopp_common
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
