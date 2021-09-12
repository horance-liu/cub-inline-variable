file(GLOB srcs CONFIGURE_DEPENDS
  *.cc
)

add_executable(cub-inline-variable-test ${srcs})

target_link_libraries(cub-inline-variable-test
  PRIVATE
    cub::inline_variable
    cctest::cctest_main
    cctest::cctest
)

add_test(NAME cub-inline-variable-test COMMAND cub-inline-variable-test)