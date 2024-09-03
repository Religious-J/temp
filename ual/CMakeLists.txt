cmake_minimum_required(VERSION 3.10.2)

# project(ual)

set(UAL_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SRC_UAL_COMMON "${UAL_DIR}/common/*.cpp")
file(GLOB_RECURSE SRC_UAL_OPS "${UAL_DIR}/ops/*.cpp")
file(GLOB_RECURSE SRC_UAL_KERNEL "${UAL_DIR}/kernel/*.scpp")

foreach(ITEM ${SRC_UAL_COMMON})
    message(VERBOSE "ual common file is ${ITEM}")
endforeach()

foreach(ITEM ${SRC_UAL_OPS})
    message(VERBOSE "ual ops file is ${ITEM}")
endforeach()

foreach(ITEM ${SRC_UAL_KERNEL})
    message(VERBOSE "ual kernel file is ${ITEM}")
endforeach()

list(APPEND SRC_UAL 
    ${SRC_UAL_COMMON} 
    ${SRC_UAL_OPS} 
    ${SRC_UAL_KERNEL})

set(SRC_UAL ${SRC_UAL} PARENT_SCOPE)
