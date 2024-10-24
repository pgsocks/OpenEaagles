cmake_minimum_required(VERSION 3.10)

project(OpenEaagles VERSION 17.06)

option(OPENEAAGLES_MODELS "Build models with JSBSim" OFF)
option(OPENEAAGLES_GRAPHICS "Build the graphics module" OFF)
option(OPENEAAGLES_INTEROP "Build the interop modules" OFF)
option(OPENEAAGLES_INTEROP_HLA "Build the interop HLA module" OFF)
option(OPENEAAGLES_INTEROP_RPRFOM "Build the interop RPRFOM module" OFF)
option(OPENEAAGLES_INTEROP_DIS "Build the interop DIS module" ON)
option(OPENEAAGLES_OTW "Build the OTW module" OFF)
option(OPENEAAGLES_RPF "Build the RPF module" ON)
option(OPENEAAGLES_DAFIF "Build the DAFIF module" ON)
option(OPENEAAGLES_IODEVICE "Build the IODEVICE module" ON)
option(OPENEAAGLES_LINEARSYSTEM "Build the LINEARSYSTEM module" ON)
option(OPENEAAGLES_SIMULATION "Build the SIMULATION module" ON)
option(OPENEAAGLES_TERRAIN "Build the TERRAIN module" ON)
option(OPENEAAGLES_RECORDER "Build the RECORDER module" ON)
option(OPENEAAGLES_INSTRUMENTS "Build the INSTRUMENTS module" ON)
option(OPENEAAGLES_GUI "Build the GUI module" ON)

include_directories(include)

add_subdirectory(src)

