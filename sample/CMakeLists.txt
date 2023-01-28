add_executable(qcolorpicker_sample sample.cpp)

target_link_libraries(qcolorpicker_sample Qt::Core Qt::Gui Qt::Widgets qcolorpicker::lib)
