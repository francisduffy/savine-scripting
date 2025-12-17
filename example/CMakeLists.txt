add_executable(cli_debugger cli_debugger.cpp)
target_link_libraries(cli_debugger PRIVATE scripting_core)

add_executable(evaluator evaluator.cpp)
target_link_libraries(evaluator PRIVATE scripting_core)
