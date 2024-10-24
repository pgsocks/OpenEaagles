set(OpenEaagles_INSTALL_TARGETS)

add_subdirectory(base)
list(APPEND OpenEaagles_INSTALL_TARGETS base)
if(OPENEAAGLES_DAFIF)
	add_subdirectory(dafif)
	list(APPEND OpenEaagles_INSTALL_TARGETS dafif)
endif()
if(OPENEAAGLES_IODEVICE)
	add_subdirectory(iodevice)
	list(APPEND OpenEaagles_INSTALL_TARGETS iodevice)
endif()
if(OPENEAAGLES_LINEARSYSTEM)
	add_subdirectory(linearsystem)
	list(APPEND OpenEaagles_INSTALL_TARGETS linearsystem)
endif()
if(OPENEAAGLES_SIMULATION)
	add_subdirectory(simulation)
	list(APPEND OpenEaagles_INSTALL_TARGETS simulation)
	if(OPENEAAGLES_INTEROP)
		add_subdirectory(interop/common)
		list(APPEND OpenEaagles_INSTALL_TARGETS interop_common)
		if(OPENEAAGLES_INTEROP_DIS)
			add_subdirectory(interop/dis)
			list(APPEND OpenEaagles_INSTALL_TARGETS interop_dis)
		endif()
		if(OPENEAAGLES_INTEROP_HLA)
			add_subdirectory(interop/hla)
			list(APPEND OpenEaagles_INSTALL_TARGETS interop_hla)
		endif()
		if(OPENEAAGLES_INTEROP_RPRFOM)
			add_subdirectory(interop/rprfom)
			list(APPEND OpenEaagles_INSTALL_TARGETS interop_rprfom)
		endif()
		if(OPENEAAGLES_OTW)
			add_subdirectory(otw)
			list(APPEND OpenEaagles_INSTALL_TARGETS otw)
		endif()
		if(OPENEAAGLES_RPF)
			add_subdirectory(map/rpf)
			list(APPEND OpenEaagles_INSTALL_TARGETS map_rpf)
		endif()
	endif()
endif()
if(OPENEAAGLES_TERRAIN)
	add_subdirectory(terrain)
	list(APPEND OpenEaagles_INSTALL_TARGETS terrain)
endif()
if(OPENEAAGLES_MODELS)
	add_subdirectory(models)
	list(APPEND OpenEaagles_INSTALL_TARGETS models)
	if(OPENEAAGLES_RECORDER)
		add_subdirectory(recorder)
		list(APPEND OpenEaagles_INSTALL_TARGETS recorder)
	endif()
endif()
if(OPENEAAGLES_GRAPHICS)
	add_subdirectory(graphics)
	list(APPEND OpenEaagles_INSTALL_TARGETS graphics)
	if(OPENEAAGLES_GUI)
		add_subdirectory(gui/glut)
		list(APPEND OpenEaagles_INSTALL_TARGETS gui_glut)
	endif()
	if(OPENEAAGLES_INSTRUMENTS)
		add_subdirectory(instruments)
		list(APPEND OpenEaagles_INSTALL_TARGETS instruments)
	endif()
endif()

install (
	TARGETS ${OpenEaagles_INSTALL_TARGETS}
	EXPORT OpenEaaglesTargets
)
install (
	EXPORT OpenEaaglesTargets
	FILE OpenEaaglesTargets.cmake
	NAMESPACE OpenEaagles::
	DESTINATION lib/cmake/OpenEaagles
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file (
	${CMAKE_CURRENT_BINARY_DIR}/OpenEaaglesConfigVersion.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)
configure_package_config_file (
	OpenEaaglesConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/OpenEaaglesConfig.cmake
	INSTALL_DESTINATION lib/cmake/OpenEaagles
)

install (FILES
	${CMAKE_CURRENT_BINARY_DIR}/OpenEaaglesConfigVersion.cmake
	${CMAKE_CURRENT_BINARY_DIR}/OpenEaaglesConfig.cmake
	DESTINATION lib/cmake/OpenEaagles
)
