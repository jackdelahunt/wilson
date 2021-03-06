cmake_minimum_required(VERSION 3.20)
project(wilson)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "vendor/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(
                wilson game/main.cpp
                game/PlayerComponent.cpp game/PlayerComponent.h
                core/json.hpp
        core/Entity.cpp core/Entity.h
                core/Component.h
                core/SpriteComponent.cpp core/SpriteComponent.h
                core/Window.cpp core/Window.h
                core/Resources.cpp core/Resources.h
                core/Transform.h
                core/wilson.h
                core/AnimatedSpriteComponent.cpp core/AnimatedSpriteComponent.h
                core/TilemapComponent.cpp core/TilemapComponent.h
        )

target_link_libraries(wilson sfml-graphics sfml-audio)