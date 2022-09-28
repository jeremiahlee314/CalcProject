# CMake generated Testfile for 
# Source directory: /home/jeremiah/Documents/calcproject/1_SimpleCalc
# Build directory: /home/jeremiah/Documents/calcproject/1_SimpleCalc/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestSimpleCalc "bash" "/home/jeremiah/Documents/calcproject/1_SimpleCalc/local_tester.sh" "1_SimpleCalc")
set_tests_properties(TestSimpleCalc PROPERTIES  WORKING_DIRECTORY "/home/jeremiah/Documents/calcproject/1_SimpleCalc" _BACKTRACE_TRIPLES "/home/jeremiah/Documents/calcproject/1_SimpleCalc/CMakeLists.txt;26;add_test;/home/jeremiah/Documents/calcproject/1_SimpleCalc/CMakeLists.txt;0;")
