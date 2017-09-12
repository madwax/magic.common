cmake_minimum_required(VERSION 3.1.0)

add_subdirectory( "common" )
add_subdirectory( "comms" )
add_subdirectory( "component_base" )
add_subdirectory( "service_base" )
add_subdirectory( "devicemanager" )

set_target_properties( Magic.Common PROPERTIES FOLDER Common/libs )
set_target_properties( Magic.Comms PROPERTIES FOLDER Common/libs )
set_target_properties( Magic.Base.Service PROPERTIES FOLDER Common/libs )
set_target_properties( Magic.Base.Component PROPERTIES FOLDER Common/libs )
set_target_properties( Magic.DeviceManager PROPERTIES FOLDER Common/libs )



