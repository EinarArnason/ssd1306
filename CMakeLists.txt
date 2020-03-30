cmake_minimum_required(VERSION 3.0.0)
project(SSD1306 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(${PROJECT_NAME} SSD1306.cpp Graphic.cpp TextBox.cpp)

if (NOT TARGET I2C)
    add_subdirectory (i2c)
endif()

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_SOURCE_DIR}/i2c/)
target_link_libraries(${PROJECT_NAME} I2C)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
