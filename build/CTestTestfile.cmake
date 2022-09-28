# CMake generated Testfile for 
# Source directory: /home/jeremiah/Documents/calcproject
# Build directory: /home/jeremiah/Documents/calcproject/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestSimpleCalc "bash" "/home/jeremiah/Documents/calcproject/local_tester.sh" "1_SimpleCalc")
set_tests_properties(TestSimpleCalc PROPERTIES  WORKING_DIRECTORY "/home/jeremiah/Documents/calcproject" _BACKTRACE_TRIPLES "/home/jeremiah/Documents/calcproject/CMakeLists.txt;37;add_test;/home/jeremiah/Documents/calcproject/CMakeLists.txt;0;")
add_test(TestFileCalc "bash" "/home/jeremiah/Documents/calcproject/local_tester.sh" "2_FileCalc")
set_tests_properties(TestFileCalc PROPERTIES  WORKING_DIRECTORY "/home/jeremiah/Documents/calcproject" _BACKTRACE_TRIPLES "/home/jeremiah/Documents/calcproject/CMakeLists.txt;42;add_test;/home/jeremiah/Documents/calcproject/CMakeLists.txt;0;")
add_test(TestDataStructures1 "bash" "/home/jeremiah/Documents/calcproject/local_tester.sh" "3_DataStructures1")
set_tests_properties(TestDataStructures1 PROPERTIES  WORKING_DIRECTORY "/home/jeremiah/Documents/calcproject" _BACKTRACE_TRIPLES "/home/jeremiah/Documents/calcproject/CMakeLists.txt;47;add_test;/home/jeremiah/Documents/calcproject/CMakeLists.txt;0;")
add_test(TestThreadCalc "bash" "/home/jeremiah/Documents/calcproject/local_tester.sh" "4_ThreadCalc")
set_tests_properties(TestThreadCalc PROPERTIES  WORKING_DIRECTORY "/home/jeremiah/Documents/calcproject" _BACKTRACE_TRIPLES "/home/jeremiah/Documents/calcproject/CMakeLists.txt;52;add_test;/home/jeremiah/Documents/calcproject/CMakeLists.txt;0;")
subdirs("0_Common")
subdirs("1_SimpleCalc")
subdirs("2_FileCalc")
subdirs("3_DataStructures1")
subdirs("4_ThreadCalc")
