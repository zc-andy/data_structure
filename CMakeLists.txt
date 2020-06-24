# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.12.0)

if(CMAKE_BUILD_RPATH)
    message("CMAKE_BUILD_RPATH: ${CMAKE_BUILD_RPATH}")
endif()

# 项目信息
project (data_structure)
set (DS_MAJOR_VERSION 1)
set (DS_MINOR_VERSION 0)
set (DS_PATCH_VERSION 0)

# 设置编译选项
if (CMAKE_BUILD_RPATH AND (CMAKE_BUILD_TYPE MATCHES GTEST))
	add_definitions(-D_GTEST_)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -g -fprofile-arcs -ftest-coverage") 
endif()

# 设置源文件路径
aux_source_directory(src DS_SRC_FILES)

# 设置测试代码路径
if (CMAKE_BUILD_TYPE MATCHES GTEST)
	aux_source_directory(gtest DS_TEST_FILES)
endif()	

# 头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 库文件目录
include_directories(${CMAKE_BUILD_RPATH}/include)
link_directories(${CMAKE_BUILD_RPATH}/lib)

if (CMAKE_BUILD_TYPE MATCHES GTEST)
	#添加编译选项
	add_executable(ds_gtest ${DS_SRC_FILES} 
					${DS_TEST_FILES})
	target_link_libraries(ds_gtest PRIVATE gtest)
	target_link_libraries(ds_gtest PRIVATE gcov)
endif()
