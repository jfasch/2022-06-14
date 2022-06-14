ADD_EXECUTABLE(
  exercises-suite

  bag-copy-insert-find-suite.cpp
  bag-copy-remove-suite.cpp
  bag-unique-suite.cpp

  bag-shared-basic-suite.cpp
  bag-shared-insert-const-ref.cpp
  bag-shared-insert-move.cpp

)
TARGET_LINK_LIBRARIES(exercises-suite gtest_main)
