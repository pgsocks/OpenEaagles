add_library(graphics
	readouts/AsciiText.cpp
	readouts/Cursor.cpp
	readouts/DirectionReadout.cpp
	readouts/HexReadout.cpp
	readouts/LatitudeReadout.cpp
	readouts/LongitudeReadout.cpp
	readouts/NumericReadout.cpp
	readouts/OctalReadout.cpp
	readouts/ReformatScanner.cpp
	readouts/Rotary.cpp
	readouts/Rotary2.cpp
	readouts/TimeReadout.cpp
	BmpTexture.cpp
	BitmapFont.cpp
	Clip3D.cpp
	ColorGradient.cpp
	ColorRotary.cpp
	Display.cpp
	factory.cpp
	Field.cpp
	Font.cpp
	FtglFonts.cpp
	Graphic.cpp
	Image.cpp
	Material.cpp
	Page.cpp
	Polygon.cpp
	Rotators.cpp
	Scanline.cpp
	Shapes.cpp
	StrokeFont.cpp
	SymbolLoader.cpp
	Texture.cpp
	Translator.cpp
	MfdPage.cpp
	MapPage.cpp
)

target_include_directories (
	graphics
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

install (
	TARGETS graphics
)

install (
	DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
