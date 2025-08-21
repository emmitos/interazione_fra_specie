# CMake generated Testfile for 
# Source directory: /Users/emma/progetto
# Build directory: /Users/emma/progetto/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[simulation_test]=] "/Users/emma/progetto/build/Debug/simulation_test")
  set_tests_properties([=[simulation_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/emma/progetto/CMakeLists.txt;53;add_test;/Users/emma/progetto/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[simulation_test]=] "/Users/emma/progetto/build/Release/simulation_test")
  set_tests_properties([=[simulation_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/emma/progetto/CMakeLists.txt;53;add_test;/Users/emma/progetto/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[simulation_test]=] "/Users/emma/progetto/build/RelWithDebInfo/simulation_test")
  set_tests_properties([=[simulation_test]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/emma/progetto/CMakeLists.txt;53;add_test;/Users/emma/progetto/CMakeLists.txt;0;")
else()
  add_test([=[simulation_test]=] NOT_AVAILABLE)
endif()
