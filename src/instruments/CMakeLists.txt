add_library(instruments
	adi/Adi.cpp
	adi/GhostHorizon.cpp
	buttons/Button.cpp
	buttons/PushButton.cpp
	buttons/RotarySwitch.cpp
	buttons/Knob.cpp
	buttons/Switch.cpp
	buttons/SolenoidSwitch.cpp
	dials/AltitudeDial.cpp
	dials/AnalogDial.cpp
	dials/DialArcSegment.cpp
	dials/DialPointer.cpp
	dials/DialTickMarks.cpp
	dials/GMeterDial.cpp
	eadi3d/Eadi3DFont.cpp
	eadi3d/Eadi3DObjects.cpp
	eadi3d/Eadi3DPage.cpp
	eadi3d/IrisGLCompat.cpp
	engines/EngPage.cpp
	gauges/AnalogGauge.cpp
	gauges/AoaIndexer.cpp
	gauges/GaugeSlider.cpp
	gauges/Tape.cpp
	gauges/TickMarks.cpp
	landinggear/LandingGear.cpp
	landinggear/LandingLight.cpp
	maps/BearingPointer.cpp
	maps/CompassRose.cpp
	factory.cpp
	Instrument.cpp
)

target_link_libraries (
	instruments
	PRIVATE
	base
	graphics
)

target_include_directories (
	instruments
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
