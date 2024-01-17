#cd C:\bld\abc-win
#cmake -SC:\pro\abc -BC:\bld\abc
##2 cmake -DCMAKE_TOOLCHAIN_FILE=C:\pro\vcpkg\scripts\buildsystems\vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows-static -DBUILD_SHARED_LIBS=OFF -SC:\pro\abc -BC:\bld\abc-win
#cd C:\bld\abc-web
##4 cmake -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=C:/pro/emsdk/upstream/emscripten/cmake/Modules/Platform/emscripten.cmake -DCMAKE_TOOLCHAIN_FILE=C:/pro/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=wasm32-emscripten -DBUILD_SHARED_LIBS=OFF -DCMAKE_GENERATOR=Ninja -DCMAKE_BUILD_TYPE=Debug -SC:/pro/abc -BC:/bld/abc-web -DCMAKE_CROSSCOMPILING_EMULATOR=C:/pro/emsdk/node/16.20.0_64bit/bin/node.exe -G Ninja  
#cmake --build .  --config Debug -j 16

cmake_minimum_required(VERSION 3.25)
project(abc VERSION 0.0.1.0)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
include(Dependencies.cmake)

add_library(abc_lib
  ./lib/abc_lib.cpp
  ./lib/abc_lib.h
)

add_executable(abc_exe
  abc.cpp
)

 target_link_libraries(abc_exe
  abc_lib
  argh
  ONBINGS::bofstd
)
if (EMSCRIPTEN)
  message("===EMSCRIPTEN=== Add .html to .wasm and .js files")
  set(CMAKE_EXECUTABLE_SUFFIX ".html")   #to generate .html in addition to .js and .wasm
  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -pthread")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s TOTAL_STACK=8MB -s TOTAL_MEMORY=256MB -s PTHREAD_POOL_SIZE=4 --embed-file ${CMAKE_CURRENT_SOURCE_DIR}/data@data")    
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  endif ()
endif()