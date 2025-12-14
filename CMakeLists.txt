cmake_minimum_required(VERSION 3.23)
project(savine-scripting VERSION 1.0.0)

# Require C++14 or higher
if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
elseif(CMAKE_CXX_STANDARD LESS 14)
    message(FATAL_ERROR "Please specify CMAKE_CXX_STANDARD of 14 or higher")
endif()

if (NOT DEFINED CMAKE_CXX_STANDARD_REQUIRED)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# Core scripting library.
add_subdirectory(core)

# Build XLL if on Windows.
if (MSVC)

    # Prefer cache variable XLL_SDK_ROOT. If not provided, seed it from the environment variable.
    if (NOT DEFINED XLL_SDK_ROOT)
        if (DEFINED ENV{EXCEL_2013_XLL_SDK_ROOT})
            set(XLL_SDK_ROOT $ENV{EXCEL_2013_XLL_SDK_ROOT} CACHE PATH "Path to Excel 2013 XLL SDK")
        else()
            # Create the cache entry so users see it in GUIs even if empty.
            set(XLL_SDK_ROOT "" CACHE PATH "Path to Excel 2013 XLL SDK")
        endif()
    endif()

    if ($CACHE{XLL_SDK_ROOT} STREQUAL "")
        message(FATAL_ERROR "Provide path to Excel 2013 XLL SDK via environment variable 
            EXCEL_2013_XLL_SDK_ROOT or -DXLL_SDK_ROOT=<path>")
    endif()

    add_subdirectory(xll)
endif()

# Example usage
add_subdirectory(example)

# Add a target for formatting all files using clang-format.
find_program(CLANG_FORMAT clang-format PATHS "$ENV{VCINSTALLDIR}Tools/Llvm/x64/bin")

if(CLANG_FORMAT)
    file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h *.hpp *.c)

    add_custom_target(format
        COMMAND ${CLANG_FORMAT} -i ${ALL_SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-format on all source files"
    )
else()
    message(STATUS "clang-format not found. 'format' target will not be available.")
endif()
