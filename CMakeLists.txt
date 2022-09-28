cmake_minimum_required(VERSION 3.16)

enable_testing()
set(CTEST_RERUN_FAILED ON)
set(CTEST_OUTPUT_ON_FAILURE ON)

project(
    JQRCalcProjects
    LANGUAGES "C"
    DESCRIPTION "JQR Example Projects"
)

if (DEBUG EQUAL "1")
    message("DEBUGGING VERSION")
    add_compile_definitions(DEBUG)
else()
    message("RELEASE VERSION")
endif()



include_directories(0_Common/include)
include_directories(1_SimpleCalc/include)
include_directories(2_FileCalc/include)
include_directories(3_DataStructures1/include)
include_directories(4_ThreadCalc/include)

# repeat for other projects
add_subdirectory(0_Common)
add_subdirectory(1_SimpleCalc)
add_subdirectory(2_FileCalc)
add_subdirectory(3_DataStructures1)
add_subdirectory(4_ThreadCalc)


# repeat for other projects
add_test(
    NAME TestSimpleCalc
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND bash ${CMAKE_SOURCE_DIR}/local_tester.sh 1_SimpleCalc
)
add_test(
    NAME TestFileCalc
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND bash ${CMAKE_SOURCE_DIR}/local_tester.sh 2_FileCalc
)
add_test(
    NAME TestDataStructures1
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND bash ${CMAKE_SOURCE_DIR}/local_tester.sh 3_DataStructures1
)
add_test(
    NAME TestThreadCalc
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND bash ${CMAKE_SOURCE_DIR}/local_tester.sh 4_ThreadCalc
)

