cmake_minimum_required(VERSION 2.6)

project (api CXX)

set(API_HEADERS api.h)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(API_CODEGEN_DIR "${PROJECT_BINARY_DIR}/codegen")

PREPEND(API_HEADERS_PATHS ${PROJECT_SOURCE_DIR} ${API_HEADERS})

CODEGEN_FILES(API_CODEGEN_SOURCES ${API_CODEGEN_DIR} ${API_HEADERS})

add_custom_command(OUTPUT ${API_CODEGEN_SOURCES}
    COMMAND ${NGREST_BIN_PATH}ngrestcg -i "${PROJECT_SOURCE_DIR}" -o ${API_CODEGEN_DIR} -t service ${API_HEADERS}
    DEPENDS ${API_HEADERS_PATHS}
)

file(GLOB API_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

list(APPEND API_SOURCES ${API_CODEGEN_SOURCES})

include_directories(${PROJECT_SOURCE_DIR} $ENV{NGREST_EXT_INCLUDES} ${CMAKE_SOURCE_DIR}/spdlog/include})

add_library(api MODULE ${API_SOURCES})

set_target_properties(api PROPERTIES PREFIX "")
set_target_properties(api PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SERVICES_DIR}"
)

target_link_libraries(api ngrestutils ngrestcommon ngrestjson ngrestengine $ENV{NGREST_EXT_LIBS})
