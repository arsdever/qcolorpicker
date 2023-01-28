add_library(qcolorpicker_interface INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/qcolorpicker/qcolorpicker.hpp)
add_library(qcolorpicker::interface ALIAS qcolorpicker_interface)

target_include_directories(qcolorpicker_interface
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
