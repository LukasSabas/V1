cmake_minimum_required(VERSION 3.20)
project(v1_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(v1.0)

add_executable(v1_0
	v1.0/galutinis.h
	v1.0/galutinis.cpp
	v1.0/generatorius.h
	v1.0/generatorius.cpp
	v1.0/isvedimas.h
	v1.0/isvedimas.cpp
	v1.0/ivedimas.h
	v1.0/ivedimas.cpp
	v1.0/laikmatis.h
	v1.0/skirstymas.h
	v1.0/skirstymas.cpp
	v1.0/skirstymasl.cpp
	v1.0/studentas.h
	v1.0/teigiamas.h
	v1.0/teigiamas.cpp
	v1.0/listantra.cpp
	v1.0/listpirma.cpp
	v1.0/vectorantra.cpp
	v1.0/vectorpirma.cpp
	v1.0/v1.0.cpp)