find_path(GLEW_INCLUDE_DIR GL/glew.h)
message("FIND_PATH ${GLEW_INCLUDE_DIR}")
if(NOT GLEW_LIBRARY)
    find_library(GLEW_LIBRARY_RELEASE NAMES GLEW glew32 glew glew32s PATH_SUFFIXES lib64 libx32)
    find_library(GLEW_LIBRARY_DEBUG NAMES GLEWd glew32d glewd PATH_SUFFIXES lib64)

    include(SelectLibraryConfigurations)
    select_library_configurations(GLEW)
endif ()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLEW REQUIRED_VARS GLEW_INCLUDE_DIR GLEW_LIBRARY)

if(GLEW_FOUND)
    set(GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIR})
    message("-- Found GLEW: " ${GLEW_INCLUDE_DIRS})

    if(NOT GLEW_LIBRARIES)
        set(GLEW_LIBRARIES ${GLEW_LIBRARY})
    endif()
    message("-- GLEW_LIBRARIES: " ${GLEW_LIBRARIES})

    if (NOT TARGET GLEW::GLEW)
        add_library(GLEW::GLEW UNKNOWN IMPORTED
                ../src/playground/err.cpp
                ../src/playground/err.h
                ../src/playground/err.cpp
                ../src/playground/MeshWindow.cpp
                ../src/playground/MeshWindow.h
                ../src/playground/MeshWindow.cpp
                ../src/playground/MeshWindow.h
                ../src/playground/MeshWindow.cpp
                ../src/playground/MeshWindow.h
                ../src/playground/MeshWindow1.cpp
                ../src/playground/MeshWindow1.h
                ../src/playground/MeshWindow.cpp
                ../src/playground/MeshWindow.h
                ../src/playground/window.cpp
                ../src/playground/scene.cpp
                ../src/playground/renderable.h
                ../src/playground/camera.h
                ../src/playground/objects/background.cpp
                ../src/playground/objects/background.cpp
                ../src/playground/objects/corn.cpp
                ../src/playground/objects/crow.cpp
                ../src/playground/objects/crow.cpp
                ../src/playground/objects/deer.cpp
                ../src/playground/objects/Deer_child.cpp
                ../src/playground/objects/falling_tree.cpp
                ../src/playground/shapes/cube.cpp
                ../src/playground/shapes/sphere.cpp
                ../src/playground/objects/fireflies.cpp
                ../src/playground/objects/flower.cpp
                ../src/playground/objects/ground.cpp
                ../src/playground/objects/lake.cpp
                ../src/playground/objects/moon.cpp
                ../src/playground/objects/player.cpp
                ../src/playground/tree.cpp
                ../src/playground/objects/tree.cpp
                ../src/playground/objects/wolf.cpp
                ../src/playground/MeshWindow.cpp
                ../src/playground/MeshWindow.h
                ../src/playground/object/Cube.cpp
                ../src/playground/object/Cube.h
                ../src/playground/Ground.cpp
                ../src/playground/Ground.h
                ../src/playground/object/Ground.cpp
                ../src/playground/object/Ground.h
                ../src/playground/object/Door.cpp
                ../src/playground/object/Door.h
                ../src/playground/DoorController.cpp
                ../src/playground/DoorController.h
                ../src/playground/MeshWindow.cpp
                ../src/playground/MeshWindow.h
                ../src/playground/object/RenderableObject.h
                ../src/playground/object/Cube.cpp
                ../src/playground/object/RenderableObject.cpp
                ../src/playground/object/Cube.h
                ../src/playground/object/Ground.cpp
                ../src/playground/object/Ground.h
                ../src/playground/object/Door.cpp
                ../src/playground/object/Door.h
                ../src/playground/object/DoorLeft.cpp
                ../src/playground/object/DoorLeft.h
                ../src/playground/object/DoorRight.cpp
                ../src/playground/object/DoorRight.h)
        set_target_properties(GLEW::GLEW PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${GLEW_INCLUDE_DIRS}")

        if(GLEW_LIBRARY_RELEASE)
            set_property(TARGET GLEW::GLEW APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
            set_target_properties(GLEW::GLEW PROPERTIES IMPORTED_LOCATION_RELEASE "${GLEW_LIBRARY_RELEASE}")
        endif()

        if(GLEW_LIBRARY_DEBUG)
            set_property(TARGET GLEW::GLEW APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
            set_target_properties(GLEW::GLEW PROPERTIES IMPORTED_LOCATION_DEBUG "${GLEW_LIBRARY_DEBUG}")
        endif()

        if(NOT GLEW_LIBRARY_RELEASE AND NOT GLEW_LIBRARY_DEBUG)
            set_property(TARGET GLEW::GLEW APPEND PROPERTY IMPORTED_LOCATION "${GLEW_LIBRARY}")
        endif()
    endif()
endif()

mark_as_advanced(GLEW_INCLUDE_DIR)
