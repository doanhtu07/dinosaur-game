cmake_minimum_required(VERSION 3.30)

# Change this to ON/OFF to enable/disable production build
option(PRODUCTION_BUILD "Make this a production build" ON)

set(CMAKE_CXX_STANDARD 17)

project(Dinosaur)

# === Handle source files ===

message(STATUS "Handle source files")

# Define MY_SOURCES to be a list of all the source files for my game
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

add_executable(${CMAKE_PROJECT_NAME})
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCES})

# === Handle packages ===

message(STATUS "Handle packages")

# https://github.com/microsoft/vcpkg/issues/8503
find_package(
  SFML
  COMPONENTS graphics CONFIG
  REQUIRED)

target_link_libraries(Dinosaur PRIVATE sfml-graphics)

# === Handle resources folder ===

message(STATUS "Handle resources folder")

if(PRODUCTION_BUILD)
  # setup the ASSETS_PATH macro to be in the root folder of your exe
  target_compile_definitions("${CMAKE_PROJECT_NAME}"
                             PUBLIC RESOURCES_PATH="./resources/")

  # remove the option to debug asserts.
  target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=1)

  add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources)
else()
  # This is useful to get an ASSETS_PATH in your IDE during development
  target_compile_definitions(
    "${CMAKE_PROJECT_NAME}"
    PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")

  target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=0)
endif()

# === Handle compile_commands.json for editor to lint ===

message(STATUS "Handle compile_commands.json for editor to lint")

if(PROJECT_IS_TOP_LEVEL AND UNIX)
  # Create symlink to compile_commands.json for IDE to pick it up
  execute_process(
    COMMAND
      ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
endif()
