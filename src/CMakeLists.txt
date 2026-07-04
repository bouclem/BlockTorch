file(GLOB_RECURSE BLOCKTORCH_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/blocks/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/blocks/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.h"
)

add_library(blocktorch_core STATIC ${BLOCKTORCH_SOURCES})

target_include_directories(blocktorch_core PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(blocktorch_core PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

add_executable(blocktorch main.cpp)

target_link_libraries(blocktorch PRIVATE
    blocktorch_core
)
