# Set the project name
project (utils)

# Add a library with the above sources
add_library(${PROJECT_NAME} src/apue.c)
add_library(sub::utils ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
