add_library(otw
	cigi/CigiCl.cpp
	cigi/CigiClNetwork.cpp
	cigi/OtwCigiCl.cpp
	cigi/OtwModelCigiCl.cpp
	pc/OtwPC.cpp
	Otm.cpp
	Otw.cpp
	OtwModel.cpp
	factory.cpp
)

target_include_directories (
	otw
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
