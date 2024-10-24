add_library(interop_hla
	Ambassador.cpp
	NetIO.cpp
	Nib.cpp
)

target_link_libraries (
	interop_hla
	PRIVATE
	base
)

target_include_directories (
	interop_hla
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

install (
	TARGETS interop_hla
)

install (
	DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
