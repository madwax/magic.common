cmake_minimum_required(VERSION 3.1.0)

project( Magic.Common )

set( TARGET_INCLUDE_DIR ${Magic.Common_SOURCE_DIR}/include )
set( TARGET_SOURCE_DIR ${Magic.Common_SOURCE_DIR}/src )

set( TARGET_PRIVATE_INCLUDES 
	${TARGET_INCLUDE_DIR}
	${TARGET_SOURCE_DIR}
)

# What other packages we need for this
set( TARGET_PRIVATE_LINK "" )
set( TARGET_PRIVATE_DEFINES "" )

set( TARGET_LINK "" )
set( TARGET_DEFINES "" )

set( TARGET_SOURCES
  ${TARGET_INCLUDE_DIR}/common/common.h
  ${TARGET_SOURCE_DIR}/common.cpp
)

if( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )

  list( APPEND TARGET_DEFINES "MAGIC_IS_WIN32=1" )
  list( APPEND TARGET_DEFINES "MAGIC_IS_UNIX=0" )

else()

	find_package( Threads REQUIRED )

	list( APPEND TARGET_LINK Threads::Threads )

	list( APPEND TARGET_DEFINES "MAGIC_IS_UNIX=1" )
	list( APPEND TARGET_DEFINES "MAGIC_IS_WIN32=0" )
	
	if( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )

		# IS_APPLE defined we are building on ios or osx, Both platform share much of the same userland but there are a few differences what's why we have 
		# IS_OSX and IS_IOS
		list( APPEND TARGET_DEFINES "MAGIC_IS_APPLE=1" )
		list( APPEND TARGET_DEFINES "MAGIC_IS_OSX=1" )
		list( APPEND TARGET_DEFINES "MAGIC_IS_IOS=0" )
		list( APPEND TARGET_DEFINED "MAGIC_IS_BSD=1" )

	elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )

	  list( APPEND TARGET_DEFINES "MAGIC_IS_LINUX=1" )
	  	  
		if( ANDROID_NDK )	  	  
		  list( APPEND TARGET_DEFINES "MAGIC_IS_ANDROID=1" )
		else()
		  list( APPEND TARGET_DEFINES "MAGIC_IS_ANDROID=0" )
		endif()
		
	elseif( ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD" )
  
	  list( APPEND TARGET_DEFINES "MAGIC_IS_FREEBSD=1" )
	  list( APPEND TARGET_DEFINED "MAGIC_IS_BSD=1" )

	endif()

endif()

add_library( Magic.Common STATIC ${TARGET_SOURCES} )

target_include_directories( Magic.Common PRIVATE ${TARGET_PRIVATE_INCLUDES}  )
target_link_libraries( Magic.Common PRIVATE ${TARGET_LINK} ${TARGET_PRIVATE_LINK} )
target_compile_definitions( Magic.Common PRIVATE ${TARGET_DEFINES} ${TARGET_PRIVATE_DEFINES} )

target_include_directories( Magic.Common INTERFACE $<BUILD_INTERFACE:${TARGET_INCLUDE_DIR}> )
target_link_libraries( Magic.Common INTERFACE $<BUILD_INTERFACE:${TARGET_LINK}> )
target_compile_definitions( Magic.Common INTERFACE ${TARGET_DEFINES} )


