cmake_minimum_required(VERSION 3.1.0)

project( Magic.Comms )

set( TARGET_INCLUDE_DIR ${Magic.Comms_SOURCE_DIR}/include )
set( TARGET_SOURCE_DIR ${Magic.Comms_SOURCE_DIR}/src )

set( TARGET_PRIVATE_INCLUDES 
	${TARGET_INCLUDE_DIR}
	${TARGET_SOURCE_DIR}
)

# What other packages we need for this
set( TARGET_PRIVATE_LINK "" )
set( TARGET_PRIVATE_DEFINES "" )

set( TARGET_LINK Magic.Common )
set( TARGET_DEFINES "" )

set( TARGET_SOURCES
  ${TARGET_INCLUDE_DIR}/common/comms.hh
  ${TARGET_SOURCE_DIR}/comms.cc
)

add_library( Magic.Comms STATIC ${TARGET_SOURCES} )

target_include_directories( Magic.Comms PRIVATE ${TARGET_PRIVATE_INCLUDES}  )
target_link_libraries( Magic.Comms PRIVATE ${TARGET_LINK} ${TARGET_PRIVATE_LINK} )
target_compile_definitions( Magic.Comms PRIVATE ${TARGET_DEFINES} ${TARGET_PRIVATE_DEFINES} )

target_include_directories( Magic.Comms INTERFACE $<BUILD_INTERFACE:${TARGET_INCLUDE_DIR}> )
target_link_libraries( Magic.Comms INTERFACE $<BUILD_INTERFACE:${TARGET_LINK}> )
target_compile_definitions( Magic.Comms INTERFACE ${TARGET_DEFINES} )
