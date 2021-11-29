cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "vendor/SFML-2.5.1/lib/cmake/SFML")
set(BUILD_DIR "cmake-build-debug")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)


add_library(wilson
        core/Entity.cpp core/Entity.h
        core/Component.h
        core/SpriteComponent.cpp core/SpriteComponent.h
        core/Window.cpp core/Window.h
        core/Resources.cpp core/Resources.h
        core/Transform.h
        core/wilson.h
        core/AnimatedSpriteComponent.cpp core/AnimatedSpriteComponent.h
        )

target_link_libraries(wilson sfml-graphics sfml-audio)
add_executable(game game/main.cpp)

find_library(libwilson wilson ${BUILD_DIR})
target_link_libraries(game sfml-graphics sfml-audio ${libwilson})

