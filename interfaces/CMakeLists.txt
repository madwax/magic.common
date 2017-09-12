cmake_minimum_required(VERSION 3.1.0)

add_subdirectory( "logging" )
add_subdirectory( "component" )

set_target_properties( Magic.Interface.Logging PROPERTIES FOLDER Common/interfaces )
set_target_properties( Magic.Interface.Component PROPERTIES FOLDER Common/interfaces )



