cmake_minimum_required(VERSION 3.0.0)
project(SSD1306 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(SSD1306 SSD1306.cpp Graphic.cpp TextBox.cpp)

if (NOT TARGET I2C)
    add_subdirectory (i2c)
endif()

target_include_directories(SSD1306 INTERFACE ${CMAKE_SOURCE_DIR}/i2c/)
target_link_libraries(SSD1306 I2C)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
