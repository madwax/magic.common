cmake_minimum_required(VERSION 3.1.0)

project( Magic.Base.Service )

set( TARGET_INCLUDE_DIR ${Magic.Base.Service_SOURCE_DIR}/include )
set( TARGET_SOURCE_DIR ${Magic.Base.Service_SOURCE_DIR}/src )

set( TARGET_PRIVATE_INCLUDES 
	${TARGET_INCLUDE_DIR}
	${TARGET_SOURCE_DIR}
)

# What other packages we need for this
set( TARGET_PRIVATE_LINK "" )
set( TARGET_PRIVATE_DEFINES "" )

set( TARGET_LINK Magic.Interface.Logging Magic.Interface.Component  )
set( TARGET_DEFINES "" )

set( TARGET_SOURCES
  ${TARGET_INCLUDE_DIR}/common/service_application.hh
  ${TARGET_SOURCE_DIR}/service_application.cc
)

add_library( Magic.Base.Service STATIC ${TARGET_SOURCES} )

target_include_directories( Magic.Base.Service PRIVATE ${TARGET_PRIVATE_INCLUDES}  )
target_link_libraries( Magic.Base.Service PRIVATE ${TARGET_LINK} ${TARGET_PRIVATE_LINK} )
target_compile_definitions( Magic.Base.Service PRIVATE ${TARGET_DEFINES} ${TARGET_PRIVATE_DEFINES} )

target_include_directories( Magic.Base.Service INTERFACE $<BUILD_INTERFACE:${TARGET_INCLUDE_DIR}> )
target_link_libraries( Magic.Base.Service INTERFACE $<BUILD_INTERFACE:${TARGET_LINK}> )
target_compile_definitions( Magic.Base.Service INTERFACE ${TARGET_DEFINES} )
