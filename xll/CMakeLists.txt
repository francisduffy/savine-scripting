add_library(scripting_xll SHARED)

target_sources(scripting_xll
    PRIVATE
        xlExport.cpp
        xlOper12.cpp

    PUBLIC
        FILE_SET scripting_xll_HEADERS
        TYPE HEADERS
        FILES
            xlOper12.h
)

set_target_properties(scripting_xll PROPERTIES SUFFIX ".xll")

target_include_directories(scripting_xll PUBLIC ${XLL_SDK_ROOT}/include)
set(LIB_SUB_DIR "$<IF:$<CONFIG:Debug>,Debug,Release>")
target_link_directories(scripting_xll PUBLIC ${XLL_SDK_ROOT}/lib/x64/${LIB_SUB_DIR})
target_link_libraries(scripting_xll PUBLIC scripting_core frmwrk32.lib xlcall32.lib)
