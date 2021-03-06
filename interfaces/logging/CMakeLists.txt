cmake_minimum_required(VERSION 3.1.0)

project( Magic.Interface.Logging )

set( TARGET_INCLUDE_DIR ${Magic.Interface.Logging_SOURCE_DIR}/include )
set( TARGET_SOURCE_DIR ${Magic.Interface.Logging_SOURCE_DIR}/src )

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
  ${TARGET_INCLUDE_DIR}/common/interfaces/logging.hh
  ${TARGET_SOURCE_DIR}/logging.cc
)
add_library( Magic.Interface.Logging STATIC ${TARGET_SOURCES} )

target_include_directories( Magic.Interface.Logging PRIVATE ${TARGET_PRIVATE_INCLUDES}  )
target_link_libraries( Magic.Interface.Logging PRIVATE ${TARGET_LINK} ${TARGET_PRIVATE_LINK} )
target_compile_definitions( Magic.Interface.Logging PRIVATE ${TARGET_DEFINES} ${TARGET_PRIVATE_DEFINES} )

target_include_directories( Magic.Interface.Logging INTERFACE $<BUILD_INTERFACE:${TARGET_INCLUDE_DIR}> )
target_link_libraries( Magic.Interface.Logging INTERFACE $<BUILD_INTERFACE:${TARGET_LINK}> )
target_compile_definitions( Magic.Interface.Logging INTERFACE ${TARGET_DEFINES} )
