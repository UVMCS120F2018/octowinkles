cmake_minimum_required(VERSION 3.8)
project(Octowinkle)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib")
endif (WIN32)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wno-deprecated -Wreturn-type -Werror")

find_package (OpenGL REQUIRED)

if (APPLE)
    find_package(GLUT REQUIRED)
endif (APPLE)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif ()

file(GLOB SOURCE_FILES
        engine/*.cpp
        engine/*.h
        *.cpp
        *.h
        )

add_executable(octowinkles ${SOURCE_FILES})

if (WIN32)
    target_link_libraries (octowinkles ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (octowinkles ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()