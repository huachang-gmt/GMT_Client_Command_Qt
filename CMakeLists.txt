cmake_minimum_required(VERSION 3.19)
project(GMT_Client_Command_Qt LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network)

qt_standard_project_setup()

qt_add_executable(GMT_Client_Command_Qt
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

qt_add_resources(GMT_Client_Command_Qt "resources"
    PREFIX "/"
    FILES
        Logo.png
)


target_link_libraries(GMT_Client_Command_Qt
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
)

install(TARGETS GMT_Client_Command_Qt
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET GMT_Client_Command_Qt
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
