cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
    set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(ipsort VERSION 0.0.${PATCH_VERSION})

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
set(TEST_PATH "${PROJECT_SOURCE_DIR}/tests")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

#find_package(GTest REQUIRED)
#include_directories(SYSTEM ${GTEST_INCLUDE_DIRS})
#configure_file(version.h.in version.h)

add_executable(ip_filter    ${SOURCE_PATH}/ip_filter.cpp
                            ${SOURCE_PATH}/lib.h)

add_executable(test_filter  ${TEST_PATH}/test_filter.cpp
                            ${SOURCE_PATH}/lib.h)

#add_library(ip_filter ${SOURCE_PATH}/lib.h)
#add_executable(test_version test_version.cpp)
#add_executable(mytest mytest.cpp)

set_target_properties(
    ip_filter
    test_filter
    PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)
#target_include_directories(helloworld
#    PRIVATE "${CMAKE_BINARY_DIR}"
#)

set_target_properties(
    test_filter
    PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        INCLUDE_DIRECTORIES ${SOURCE_PATH}
)

target_link_libraries(test_filter
    ${Boost_LIBRARIES}
#    ip_filter
)

#find_package(Threads)

#target_link_libraries(mytest ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} helloworld)



if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
    target_compile_options(test_filter PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT zonner2785@gmail.com)

include(CPack)

enable_testing()

#add_test(test_version test_version)

#add_test(NAME mytest COMMAND mytest)
