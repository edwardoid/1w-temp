cmake_minimum_required(VERSION 3.5)
project(w1temp VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/include/*.cpp")
file(GLOB INCLUDES "${CMAKE_CURRENT_LIST_DIR}/include/*.h")

if (LIBOWT_SHARED)
   add_library(${PROJECT_NAME} SHARED ${SOURCES})
else()
   add_library(${PROJECT_NAME} STATIC ${SOURCES})
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE 1)
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/ow_bus.h)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/ow_device.h)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

if (BUILD_TEST)
   file(GLOB TEST_SOURCES "tests/*.cpp")
   add_executable(${PROJECT_NAME}_test ${PROJECT_NAME} ${TEST_SOURCES})
   include_directories(${PROJECT_NAME}_test "include")

   target_link_libraries (${PROJECT_NAME}_test ${PROJECT_NAME})
endif()

