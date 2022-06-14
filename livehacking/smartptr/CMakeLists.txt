ADD_EXECUTABLE(unique-ptr unique-ptr.cpp)
TARGET_LINK_LIBRARIES(unique-ptr Threads::Threads)

ADD_EXECUTABLE(move move.cpp)
TARGET_LINK_LIBRARIES(move Threads::Threads)
