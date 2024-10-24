find_package(protobuf CONFIG REQUIRED)

add_library(recorder
	protobuf/DataRecord.proto
	DataRecorder.cpp
	DataRecordHandle.cpp
	factory.cpp
	FileReader.cpp
	FileWriter.cpp
	InputHandler.cpp
	NetInput.cpp
	NetOutput.cpp
	OutputHandler.cpp
	PrintHandler.cpp
	PrintPlayer.cpp
	PrintSelected.cpp
	TabPrinter.cpp
)

target_link_libraries (
	recorder
	PRIVATE
	base
	simulation
	models
	protobuf::libprotobuf
	protobuf::libprotoc
)
target_include_directories (
	recorder
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	# Since Protobuf generates code in the binary dir,
	# it's necessary to include headers from there as well.
	$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

protobuf_generate (
	TARGET recorder
	APPEND_PATH ""
	PROTOC_OUT_DIR include/openeaagles/recorder/protobuf
)

install (
	DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}/include/
		# Generated Protobuf headers must also be installed.
		${CMAKE_CURRENT_BINARY_DIR}/include/
	DESTINATION include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
