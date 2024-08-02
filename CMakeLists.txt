cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)

project(Dinosaur)

# https://github.com/microsoft/vcpkg/issues/8503
find_package(SFML COMPONENTS graphics CONFIG REQUIRED)

add_executable(Dinosaur src/game.cpp src/trex.cpp)

target_link_libraries(Dinosaur PRIVATE sfml-graphics)

# https://thomas.trocha.com/blog/cmake--copy-files-after-build/
# https://stackoverflow.com/questions/13429656/how-to-copy-contents-of-a-directory-into-build-directory-after-make-with-cmake
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_directory
#     ${CMAKE_SOURCE_DIR}/src/images
#     ${CMAKE_BINARY_DIR}/images
# )

# https://stackoverflow.com/questions/59263015/cmake-how-to-change-compile-commands-json-output-location
message(STATUS "Symlinking compile_commands.json")
if (PROJECT_IS_TOP_LEVEL AND UNIX)
  # Create symlink to compile_commands.json for IDE to pick it up
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
endif()
