cmake_minimum_required(VERSION 3.20)
project(wilson)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "vendor/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(wilson main.cpp Entity.cpp Entity.h Component.h SpriteComponent.cpp SpriteComponent.h Window.cpp Window.h Resources.cpp Resources.h Transform.h)
target_link_libraries(wilson sfml-graphics sfml-audio)
