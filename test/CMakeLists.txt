find_package(Qt${QT_VERSION} REQUIRED COMPONENTS Test)

add_executable(qcolorpicker_test_ui test_qcolorpicker.cpp)
add_executable(qcolorpicker::test::ui ALIAS qcolorpicker_test_ui)

target_link_libraries(qcolorpicker_test_ui PUBLIC Qt::Test qcolorpicker::lib)

add_test(NAME qcolorpicker_test_ui COMMAND qcolorpicker_test_ui)
