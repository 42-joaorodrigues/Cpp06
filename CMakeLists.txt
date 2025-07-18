cmake_minimum_required(VERSION 3.31)
project(06)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00 CPP_Module_06/ex00/ScalarConverter.cpp
		CPP_Module_06/ex00/main.cpp
		CPP_Module_06/ex00/Makefile
		CPP_Module_06/ex00/ScalarConverter.hpp)
add_executable(ex01 CPP_Module_06/ex01/main.cpp CPP_Module_06/ex01/Makefile CPP_Module_06/ex01/Serializer.cpp CPP_Module_06/ex01/Serializer.hpp)
add_executable(ex02 CPP_Module_06/ex02/A.hpp CPP_Module_06/ex02/B.hpp CPP_Module_06/ex02/Base.hpp CPP_Module_06/ex02/C.hpp CPP_Module_06/ex02/main.cpp CPP_Module_06/ex02/Makefile)
