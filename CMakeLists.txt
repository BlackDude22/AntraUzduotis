cmake_minimum_required(VERSION 3.10)

project(AntraUzduotis)


set(CMAKE_CXX_STANDARD 11)


include_directories(.)


add_executable(
	AntraUzduotis

        antra_math.cpp

        antra_math.h

        antra_uzduotis.cpp

        student.cpp

        student.h)
