cmake_minimum_required(VERSION 3.1.0)

project( Magic.DeviceManager )

set( TARGET_INCLUDE_DIR ${Magic.DeviceManager_SOURCE_DIR}/include )
set( TARGET_SOURCE_DIR ${Magic.DeviceManager_SOURCE_DIR}/src )

set( TARGET_PRIVATE_INCLUDES 
	${TARGET_INCLUDE_DIR}
	${TARGET_SOURCE_DIR}
)

# What other packages we need for this
set( TARGET_PRIVATE_LINK "" )
set( TARGET_PRIVATE_DEFINES "" )

set( TARGET_LINK Magic.Interface.Logging Magic.Comms )
set( TARGET_DEFINES "" )

set( TARGET_SOURCES
  ${TARGET_INCLUDE_DIR}/common/devicemanager.hh
  ${TARGET_SOURCE_DIR}/devicemanager.cc
)
add_library( Magic.DeviceManager STATIC ${TARGET_SOURCES} )

target_include_directories( Magic.DeviceManager PRIVATE ${TARGET_PRIVATE_INCLUDES}  )
target_link_libraries( Magic.DeviceManager PRIVATE ${TARGET_LINK} ${TARGET_PRIVATE_LINK} )
target_compile_definitions( Magic.DeviceManager PRIVATE ${TARGET_DEFINES} ${TARGET_PRIVATE_DEFINES} )

target_include_directories( Magic.DeviceManager INTERFACE $<BUILD_INTERFACE:${TARGET_INCLUDE_DIR}> )
target_link_libraries( Magic.DeviceManager INTERFACE $<BUILD_INTERFACE:${TARGET_LINK}> )
target_compile_definitions( Magic.DeviceManager INTERFACE ${TARGET_DEFINES} )
