# SSD1306 library

## The What

C++ driver library for the SSD1306 OLED, optimized for speed.

## The Why

Due to the non-linear memory addressing of the SSD1306, fast writing is not straightforward. This library is an attempt to address the issue.

## The How

### Using cmake

```cmake
add_subdirectory(${ssd1306Dir})
target_include_directories(${PROJECT_NAME} PRIVATE ${ssd1306Dir})
target_link_libraries(${PROJECT_NAME} SSD1306)
```

## The Who

Einar Arnason  
<https://github.com/EinarArnason>  
<https://www.linkedin.com/in/einararnason/>
