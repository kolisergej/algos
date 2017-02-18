aux_source_directory(. libalgos_SRC)

add_library(libalgos SHARED ${libalgos_SRC})

target_include_directories(libalgos PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
