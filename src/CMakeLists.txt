cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
# set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Protobuf REQUIRED)


# Generate the .h and .cxx files
file(GLOB proto_file ${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${proto_file})

file(GLOB ads_src "*.cc")
add_executable(ads_viz ${ads_src} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(ads_viz   Qt5::Widgets
                                Qt5::Gui
                                Qt5::Core
                                Qt5::OpenGL
                                ${PROTOBUF_LIBRARIES}
                                ${OPENGL_LIBRARIES})
