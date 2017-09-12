cmake_minimum_required(VERSION 3.1.0)

add_subdirectory( "cJSON" )
add_subdirectory( "zlib" )
add_subdirectory( "libuv" )
add_subdirectory( "tinyxml2" )

set_target_properties( cJSON PROPERTIES FOLDER Common/3ndparty )
set_target_properties( libuv PROPERTIES FOLDER Common/3ndparty )
set_target_properties( tinyxml2 PROPERTIES FOLDER Common/3ndparty )
set_target_properties( zlib PROPERTIES FOLDER Common/3ndparty )



