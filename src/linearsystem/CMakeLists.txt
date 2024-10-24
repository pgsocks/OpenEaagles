add_library(linearsystem
	DiffEquation.cpp
	FirstOrderTf.cpp
	LagFilter.cpp
	Limit01.cpp
	Limit11.cpp
	Limit.cpp
	LimitFunc.cpp
	LowpassFilter.cpp
	SaH.cpp
	ScalerFunc.cpp
	SecondOrderTf.cpp
	Sz1.cpp
	Sz2.cpp
)

target_link_libraries (
	linearsystem
	PRIVATE
	base
)

target_include_directories (
	linearsystem
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

install (
	TARGETS linearsystem
)

install (
	DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
