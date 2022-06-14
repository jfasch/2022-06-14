ADD_EXECUTABLE(overview overview.cpp)
TARGET_LINK_LIBRARIES(overview Threads::Threads)

ADD_EXECUTABLE(override-final override-final.cpp)
TARGET_LINK_LIBRARIES(override-final Threads::Threads)

ADD_EXECUTABLE(enum-class enum-class.cpp)
TARGET_LINK_LIBRARIES(enum-class Threads::Threads)

ADD_EXECUTABLE(ambiguous-init ambiguous-init.cpp)
TARGET_LINK_LIBRARIES(ambiguous-init Threads::Threads)


ADD_SUBDIRECTORY(smartptr)
