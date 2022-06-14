ADD_EXECUTABLE(overview overview.cpp)
TARGET_LINK_LIBRARIES(overview Threads::Threads)

ADD_EXECUTABLE(unique-ptr unique-ptr.cpp)
TARGET_LINK_LIBRARIES(unique-ptr Threads::Threads)

ADD_EXECUTABLE(override-final override-final.cpp)
TARGET_LINK_LIBRARIES(override-final Threads::Threads)
