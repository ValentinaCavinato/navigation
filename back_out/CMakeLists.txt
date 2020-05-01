cmake_minimum_required(VERSION 2.8.3)
project(back_out)

find_package(catkin REQUIRED
    COMPONENTS
        cmake_modules
        costmap_2d
        geometry_msgs
        nav_core
        pluginlib
        roscpp
        gazebo_msgs
        )


find_package(Eigen3 REQUIRED)
remove_definitions(-DDISABLE_LIBUSB-1.0)
find_package(Boost REQUIRED COMPONENTS thread)
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
)
add_definitions(${EIGEN3_DEFINITIONS})

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES back_out
    CATKIN_DEPENDS
        geometry_msgs
        nav_core
        pluginlib
        roscpp
        costmap_2d
        gazebo_msgs
)

add_library(back_out src/back_out.cpp)
add_dependencies(back_out ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(back_out
    ${Boost_LIBRARIES}
    ${catkin_LIBRARIES}
    )

## Install project namespaced headers
install(DIRECTORY include/${PROJECT_NAME}/
    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
    FILES_MATCHING PATTERN "*.h")

install(TARGETS back_out
       DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
       )

install(FILES back_out_plugin.xml
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)


