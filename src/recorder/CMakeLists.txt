find_package(protobuf CONFIG REQUIRED)

add_library(recorder
	protobuf/DataRecord.pb.cc
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

target_link_libraries(recorder PRIVATE protobuf::libprotobuf protobuf::libprotoc)
