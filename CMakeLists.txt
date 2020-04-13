cmake_minimum_required(VERSION 2.8)

project(app)

# find opencv
find_package(OpenCV REQUIRED)

if (NOT OpenCV_FOUND)
    message(FATAL_ERROR "opencv Not Found!")
else ()
    message(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
    message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
endif (NOT OpenCV_FOUND)

add_compile_options("-O3")

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(app demo.cpp)
target_link_libraries(app ${OpenCV_LIBS}) 
