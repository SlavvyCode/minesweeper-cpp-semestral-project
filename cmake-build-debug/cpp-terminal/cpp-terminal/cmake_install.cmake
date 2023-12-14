# Install script for directory: C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/pcc_semestralka")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Program Files/JetBrains/CLion 2023.2.2/bin/mingw/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cmake-build-debug/cpp-terminal/cpp-terminal/libcpp-terminal.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cpp-terminal" TYPE FILE FILES
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/args.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/buffer.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/color.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/cursor.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/event.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/exception.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/focus.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/input.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/iostream_initializer.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/iostream.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/key.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/mouse.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/options.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/prompt.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/screen.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/stream.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/style.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/terminal_impl.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/terminal_initializer.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/terminal.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/terminfo.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/tty.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/version.hpp"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/cpp-terminal/window.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cmake-build-debug/cpp-terminal/cpp-terminal/private/libcpp-terminal-private.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cpp-terminal/cpp-terminalTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cpp-terminal/cpp-terminalTargets.cmake"
         "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cmake-build-debug/cpp-terminal/cpp-terminal/CMakeFiles/Export/f914531f6191163e7a988aed981bcf11/cpp-terminalTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cpp-terminal/cpp-terminalTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cpp-terminal/cpp-terminalTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cpp-terminal" TYPE FILE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cmake-build-debug/cpp-terminal/cpp-terminal/CMakeFiles/Export/f914531f6191163e7a988aed981bcf11/cpp-terminalTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cpp-terminal" TYPE FILE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cmake-build-debug/cpp-terminal/cpp-terminal/CMakeFiles/Export/f914531f6191163e7a988aed981bcf11/cpp-terminalTargets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cpp-terminal" TYPE FILE FILES
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cmake-build-debug/cpp-terminal/cmake/cpp-terminalConfig.cmake"
    "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cmake-build-debug/cpp-terminal/cpp-terminal/cpp-terminalConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cmake-build-debug/cpp-terminal/cpp-terminal/private/cmake_install.cmake")

endif()

