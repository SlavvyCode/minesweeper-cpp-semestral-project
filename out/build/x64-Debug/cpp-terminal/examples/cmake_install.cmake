# Install script for directory: C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/cpp-terminal/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/install/x64-Debug")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/args.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/cin_cooked.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/cin_raw.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/colors.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/cout.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/events.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/keys.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/kilo.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/menu.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/menu_window.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/minimal.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/prompt_immediate.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/prompt_multiline.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/prompt_not_immediate.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/prompt_simple.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/styles.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/slow_events.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/utf8.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/attach_console.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/examples" TYPE EXECUTABLE FILES "C:/Users/Adam/Desktop/CVUT/PCC/Semestralni Prace/pcc-semestralka/out/build/x64-Debug/cpp-terminal/examples/attach_console_minimal.exe")
endif()

