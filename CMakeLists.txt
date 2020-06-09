project(65c816-cc C)



set(CMAKE_C_STANDARD 11)



if(NOT DEFINED COMPILER_TARGET)

    set(COMPILER_TARGET wc65c816-snes-none-elf)

endif()



find_package(BISON)

find_package(FLEX)



file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/src)



bison_target(Parser src/parser.y ${CMAKE_CURRENT_BINARY_DIR}/src/parser.c)

flex_target(Lexer src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/src/lexer.c)



add_flex_bison_dependency(Lexer Parser)



include_directories(include ${CMAKE_CURRENT_BINARY_DIR}/src)



add_executable(${COMPILER_TARGET}-cc src/main.c src/cpp.c src/elf.c src/ll.c

        ${CMAKE_CURRENT_BINARY_DIR}/src/parser.c

        ${CMAKE_CURRENT_BINARY_DIR}/src/lexer.c

        ${CMAKE_CURRENT_BINARY_DIR}/src/parser.h

        include/ast.h include/cpp.h include/eval.h include/free.h

        include/ll.h include/typelist.h src/ast.c src/evalexpr.c

        src/evalfunc.c src/evalstmt.c src/free.c src/typelist.c)



install(TARGETS ${COMPILER_TARGET}-cc RUNTIME DESTINATION bin)