cmake_minimum_required(VERSION 3.5)

project(myApp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

# Make the prefix path variable visible in cmake gui.
set(CMAKE_PREFIX_PATH "" CACHE PATH "CMake prefix path")

# Set the source directory.
set(MY_SOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/src")

# Set the output directory.
set(MY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${MY_OUTPUT_DIRECTORY}")

# Set the logging target.
set(LOG_TO_WIDGET ON CACHE BOOL "Log to widget instead of console")

# Set the source files for the logging target.
if (${LOG_TO_WIDGET})
  set(LOGGING_SOURCES "${MY_SOURCE_DIRECTORY}/logger/use_widget_logger.cxx" "${MY_SOURCE_DIRECTORY}/logger/widget_logger.cxx")
  set(APPLICATION_TYPE WIN32)
else()
  set(LOGGING_SOURCES "${MY_SOURCE_DIRECTORY}/logger/use_cout_logger.cxx" "${MY_SOURCE_DIRECTORY}/logger/cout_logger.cxx")
  set(APPLICATION_TYPE)
endif()

# Add a function to copy dlls to the output directory.
string(TOLOWER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_LOWER)
function(copy_qt_dll libname)
	get_target_property(libfile ${libname} LOCATION_${CMAKE_BUILD_TYPE_LOWER})
	file(COPY ${libfile} DESTINATION ${MY_OUTPUT_DIRECTORY})
endfunction()

# Find qt and add copy the dlls.
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
copy_qt_dll(Qt5::Core)
copy_qt_dll(Qt5::Gui)
copy_qt_dll(Qt5::Widgets)

include_directories(src)
add_subdirectory(src)
