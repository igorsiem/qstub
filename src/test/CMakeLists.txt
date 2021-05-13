# Cmake file for building the test executable
#
# Copyright Igor Siemienowicz 2018
# Distributed under the Boost Software License, Version 1.0. (See
# accompanying file LICENSE_1_0.txt or copy at
# https://www.boost.org/LICENSE_1_0.txt)

file (GLOB_RECURSE TEST_SRC *.cpp)
add_executable(test-${QPRJ_PROJECT_NAME} ${TEST_SRC})
target_link_libraries(test-${QPRJ_PROJECT_NAME}
    ${QPRJ_PROJECT_NAME}-api
)
