cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED Private)
find_package(Qt5DBus REQUIRED)

set(CMAKE_AUTOMOC ON)

_populate_Gui_plugin_properties(Gui UNUSED platforminputcontexts)
get_target_property(PLUGIN_DIR Qt5::Gui IMPORTED_LOCATION_UNUSED)

include_directories(${Qt5Gui_PRIVATE_INCLUDE_DIRS})

add_library(plugin MODULE main.cpp qonboardplatforminputcontext.cpp)
target_link_libraries(plugin Qt5::Core Qt5::Gui Qt5::DBus) 
set_target_properties(plugin PROPERTIES OUTPUT_NAME onboardplatforminputcontextplugin)

install(TARGETS plugin LIBRARY DESTINATION ${PLUGIN_DIR})
