cmake_minimum_required(VERSION 3.16)

project(4_ThreadCalc)

include_directories()

add_executable(threadcalc src/threadcalc.c src/threadpool.c ../../0_Common/src/s_calc.c src/f_calc.c ../../3_DataStructures1/src/queue.c)
