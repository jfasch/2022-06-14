ADD_EXECUTABLE(overview overview.cpp)
TARGET_LINK_LIBRARIES(overview Threads::Threads)

ADD_EXECUTABLE(override-final override-final.cpp)
TARGET_LINK_LIBRARIES(override-final Threads::Threads)

ADD_EXECUTABLE(enum-class enum-class.cpp)
TARGET_LINK_LIBRARIES(enum-class Threads::Threads)

ADD_EXECUTABLE(ambiguous-init ambiguous-init.cpp)
TARGET_LINK_LIBRARIES(ambiguous-init Threads::Threads)

ADD_EXECUTABLE(closure closure.cpp)
TARGET_LINK_LIBRARIES(closure Threads::Threads)

ADD_EXECUTABLE(race-condition race-condition.cpp)
TARGET_LINK_LIBRARIES(race-condition Threads::Threads)

ADD_EXECUTABLE(promise-future promise-future.cpp)
TARGET_LINK_LIBRARIES(promise-future Threads::Threads)

ADD_EXECUTABLE(threadsafe-queue threadsafe-queue.cpp)
TARGET_LINK_LIBRARIES(threadsafe-queue Threads::Threads)


# ADD_EXECUTABLE(refconstrefcopymove refconstrefcopymove.cpp)


ADD_SUBDIRECTORY(smartptr)
