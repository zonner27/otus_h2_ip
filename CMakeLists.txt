cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
    set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(ipfilter VERSION 0.0.${PATCH_VERSION})

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
set(TEST_PATH "${PROJECT_SOURCE_DIR}/tests")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ipfilter    ${SOURCE_PATH}/ip_filter.cpp
                            ${SOURCE_PATH}/lib.h)

add_executable(test_filter  ${TEST_PATH}/test_filter.cpp
                            ${SOURCE_PATH}/lib.h)

set_target_properties(
    ipfilter
    test_filter
    PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)

set_target_properties(
    test_filter
    PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        INCLUDE_DIRECTORIES ${SOURCE_PATH}
)

target_link_libraries(test_filter
    ${Boost_LIBRARIES}
)

if (MSVC)
    target_compile_options(ipfilter PRIVATE
        /W4
    )
    target_compile_options(test_filter PRIVATE
        /W4
    )
else ()
    target_compile_options(ipfilter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS ipfilter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT zonner2785@gmail.com)

include(CPack)

enable_testing()

add_test(test_sort test_filter)
add_test(test_filter_1 test_filter)
add_test(test_filter_46_70 test_filter)
add_test(test_filter_46_any test_filter)
