cmake_minimum_required(VERSION 3.20)

project(Imaging_Tools_Analysis)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/Image_Enhancement/*.cpp"
)
message(STATUS "SOURCES: ${SOURCES}")
add_executable(Imaging_Tools_Analysis 
        main.cpp
        ${SOURCES}
)
target_include_directories(Imaging_Tools_Analysis PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Image_Enhancement"
)
target_link_libraries(Imaging_Tools_Analysis PRIVATE ${OpenCV_LIBS})