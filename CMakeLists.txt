cmake_minimum_required(VERSION 3.5)

project(unix-learning)

# debug mode
add_compile_options(-g)

#
add_subdirectory(${PROJECT_SOURCE_DIR}/utils)

# compile json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# chapter dirs
file(GLOB CHAPTERS "${PROJECT_SOURCE_DIR}/src/*")
foreach(CHAPTER ${CHAPTERS})
    file(GLOB SOURCES "${CHAPTER}/*")
    foreach(SOURCE ${SOURCES})
        file(GLOB C_SRC_CODE "${SOURCE}/*.c")
        get_filename_component(EXEC_NAME "${SOURCE}" NAME)
        add_executable(${EXEC_NAME} ${C_SRC_CODE})

        target_link_libraries(${EXEC_NAME} 
            sub::utils
        )
    endforeach()
endforeach()

