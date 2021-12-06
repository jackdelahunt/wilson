from pysemble.builders import Project
from pysemble.compilers import Gpp
import os

compiler = Gpp("c++17") # g++

working_directory = os.path.dirname(os.path.realpath(__file__))
os.environ["LD_LIBRARY_PATH"] = working_directory + "/vendor/SFML-2.5.1/lib/"


project = Project("wilson", compiler)
project.add_executables([
    "core/AnimatedSpriteComponent.cpp",
    "core/SpriteComponent.cpp",
    "core/Entity.cpp",
    "core/Resources.cpp",
    "core/TilemapComponent.cpp",
    "core/Window.cpp",
    "game/main.cpp",
    "game/PlayerComponent.cpp",
])
project.set_link_path("vendor/SFML-2.5.1/lib/")
project.add_include_directory("vendor/SFML-2.5.1/include/")
project.add_dynamic_libs([
    "sfml-graphics",
    "sfml-window",
    "sfml-system",
    "sfml-audio",
])
project.build()
project.run()
