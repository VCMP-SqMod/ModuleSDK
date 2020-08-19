cmake_minimum_required(VERSION 3.0.2)
project(SqSDK)

# Create the SqSDK library for module
add_library(SqModSDK STATIC
	include/sqlibapi.h
	include/sqmodapi.h
	include/sqaddon.h
	include/sqrat.h
	include/sqrat/sqratAllocator.h
	include/sqrat/sqratArray.h
	include/sqrat/sqratClass.h
	include/sqrat/sqratConst.h
	include/sqrat/sqratFunction.h
	include/sqrat/sqratGlobalMethods.h
	include/sqrat/sqratMemberMethods.h
	include/sqrat/sqratObject.h
	include/sqrat/sqratOverloadMethods.h
	include/sqrat/sqratScript.h
	include/sqrat/sqratTable.h
	include/sqrat/sqratTypes.h
	include/sqrat/sqratUtil.h
	include/vcmp.h
	include/vcmp20.h
	include/vcmp21.h
)
# Enable LTO
if (LTO_ENABLED)
	target_link_libraries(SqModSDK PRIVATE -flto)
endif()
# Create the SqSDK library for addons
add_library(SqAddSDK STATIC
	include/sqlibapi.h sqlibapi.cpp
	include/sqmodapi.h sqmodapi.cpp
	include/sqaddon.h
	include/sqrat.h
	include/sqrat/sqratAllocator.h
	include/sqrat/sqratArray.h
	include/sqrat/sqratClass.h
	include/sqrat/sqratConst.h
	include/sqrat/sqratFunction.h
	include/sqrat/sqratGlobalMethods.h
	include/sqrat/sqratMemberMethods.h
	include/sqrat/sqratObject.h
	include/sqrat/sqratOverloadMethods.h
	include/sqrat/sqratScript.h
	include/sqrat/sqratTable.h
	include/sqrat/sqratTypes.h
	include/sqrat/sqratUtil.h
	include/vcmp.h
	include/vcmp20.h
	include/vcmp21.h
)
# Enable LTO
if (LTO_ENABLED)
	target_link_libraries(SqAddSDK PRIVATE -flto)
endif()

# Library includes
target_include_directories(SqModSDK PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(SqAddSDK PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(SqModSDK PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(SqAddSDK PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

# Include Squirrel library
add_subdirectory(squirrel)

# Link to required libraries
target_link_libraries(SqModSDK PUBLIC Squirrel)
target_link_libraries(SqAddSDK PUBLIC SquirrelInterface)

# Checkf for server API version
if (ENABLE_API21)
	target_compile_definitions(SqModSDK PUBLIC VCMP_SDK_2_1=1)
	target_compile_definitions(SqAddSDK PUBLIC VCMP_SDK_2_1=1)
endif()
