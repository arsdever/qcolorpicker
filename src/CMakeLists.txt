set(SOURCES qcolorpicker.cpp qcolorpicker_slider.cpp)
set(HEADERS qcolorpicker_slider.hpp)
set(RESOURCES qcolorpicker_resources.qrc)

add_library(qcolorpicker_lib STATIC ${HEADERS} ${SOURCES} ${RESOURCES})
add_library(qcolorpicker::lib ALIAS qcolorpicker_lib)

target_link_libraries(qcolorpicker_lib PUBLIC qcolorpicker::interface)
