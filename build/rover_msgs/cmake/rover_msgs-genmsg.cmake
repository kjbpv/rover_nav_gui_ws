# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rover_msgs: 9 messages, 0 services")

set(MSG_I_FLAGS "-Irover_msgs:/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(rover_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavGoal.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavGoal.msg" ""
)

get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/JointAngles.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/JointAngles.msg" ""
)

get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavState.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavState.msg" ""
)

get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Arm.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Arm.msg" ""
)

get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Pololu.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Pololu.msg" ""
)

get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/All.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/All.msg" ""
)

get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Drive.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Drive.msg" ""
)

get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Chutes.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Chutes.msg" ""
)

get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/SciFeedback.msg" NAME_WE)
add_custom_target(_rover_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rover_msgs" "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/SciFeedback.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/JointAngles.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Pololu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/All.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Drive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Chutes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)
_generate_msg_cpp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/SciFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(rover_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rover_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(rover_msgs_generate_messages rover_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavGoal.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/JointAngles.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavState.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Arm.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Pololu.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/All.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Drive.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Chutes.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/SciFeedback.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_cpp _rover_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rover_msgs_gencpp)
add_dependencies(rover_msgs_gencpp rover_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rover_msgs_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/JointAngles.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Pololu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/All.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Drive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Chutes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)
_generate_msg_lisp(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/SciFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(rover_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(rover_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(rover_msgs_generate_messages rover_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavGoal.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/JointAngles.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavState.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Arm.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Pololu.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/All.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Drive.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Chutes.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/SciFeedback.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_lisp _rover_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rover_msgs_genlisp)
add_dependencies(rover_msgs_genlisp rover_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rover_msgs_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/JointAngles.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Pololu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/All.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Drive.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Chutes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)
_generate_msg_py(rover_msgs
  "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/SciFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(rover_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rover_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(rover_msgs_generate_messages rover_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavGoal.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/JointAngles.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/NavState.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Arm.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Pololu.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/All.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Drive.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/Chutes.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg/SciFeedback.msg" NAME_WE)
add_dependencies(rover_msgs_generate_messages_py _rover_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rover_msgs_genpy)
add_dependencies(rover_msgs_genpy rover_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rover_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rover_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(rover_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rover_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(rover_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rover_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(rover_msgs_generate_messages_py std_msgs_generate_messages_py)
