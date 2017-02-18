aux_source_directory(. SRCS)

ADD_EXECUTABLE(testalgos ${SRCS})

TARGET_LINK_LIBRARIES(testalgos
    libalgos
    libgtest
    libgmock
)

add_test(NAME testalgos COMMAND testalgos)
