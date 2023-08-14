add_executable(
  node
  node.cpp
)
target_link_libraries(
  node
  GTest::gtest_main
  ctda
)

include(GoogleTest)
gtest_discover_tests(node)

