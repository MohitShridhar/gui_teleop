cmake_minimum_required(VERSION 2.8.3)
project(gui_teleop)


## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  nodelet
  roscpp
  rospy
  rviz
  sensor_msgs
  std_msgs
  tf
)

catkin_package(
# INCLUDE_DIRS include
#  LIBRARIES gui_teleop
#  CATKIN_DEPENDS nodelet roscpp rospy rviz sensor_msgs std_msgs tf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

link_directories(
	${catkin_LIBRARY_DIRS}
)

## This plugin includes Qt widgets, so we must include Qt like so:
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

## I prefer the Qt signals and slots to avoid defining "emit", "slots",
## etc because they can conflict with boost signals, so define QT_NO_KEYWORDS here.
add_definitions(-DQT_NO_KEYWORDS)

## Here we specify which header files need to be run through "moc",
## Qt's meta-object compiler.
qt4_wrap_cpp(MOC_FILES
	src/gui_teleop.h
	src/drive_widget.h
)

set(SOURCE_FILES
	src/gui_teleop.cpp
	src/drive_widget.cpp
	${MOC_FILES}
)


add_library(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${catkin_LIBRARIES})

## Install rules

install(TARGETS
  ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(FILES 
  plugin_description.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY media/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/media)

install(DIRECTORY icons/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/icons)

# install(PROGRAMS scripts/send_test_msgs.py
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})




