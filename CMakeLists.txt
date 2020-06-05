project(65c816-cc C)

set(CMAKE_C_STANDARD 11)

if(NOT DEFINED COMPILER_TARGET)
    set(COMPILER_TARGET wc65c816-snes-none-elf)
endif()

add_executable(${COMPILER_TARGET}-cc src/main.c src/cpp.c src/lex.c src/parse.c src/elf.c src/ll.c)

install(TARGETS ${COMPILER_TARGET}-cc RUNTIME DESTINATION bin)