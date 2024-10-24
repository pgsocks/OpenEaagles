add_library(iodevice
	Ai2DiSwitch.cpp
	AnalogInput.cpp
	AnalogOutput.cpp
	Controller.cpp
	DiscreteInput.cpp
	DiscreteOutput.cpp
	factory.cpp
	IoData.cpp
	SignalGen.cpp
)

target_link_libraries (
	iodevice
	PRIVATE
	base
)

target_include_directories (
	iodevice
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
