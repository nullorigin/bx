cmake_minimum_required(VERSION 3.12)

project("bx" C CXX)
set(OS "linux")
set(BX_DIR ".")
set(BIMG_DIR "../bimg")
set(BGFX_DIR "../bgfx")
set(GENIE "${BX_DIR}/tools/bin/${OS}/genie ${EXTRA_GENIE_ARGS}")
set(NINJA "${BX_DIR}/tools/bin/${OS}/ninja")
set(PREFIX "/usr")
set(BIN "${PREFIX}/bin")
set(LIB "${PREFIX}/lib")
set(INCLUDE "${PREFIX}/include")
set(SHARE "${PREFIX}/share")
set(PATH "${BIN}" "${PATH}")
set(CMAKE_COMMAND "${BIN}/cmake")
set(CMAKE_ROOT "${SHARE}/cmake")
set(CMAKE_CXX_COMPILER "${BIN}/clang++")
set(CMAKE_C_COMPILER "${BIN}/clang")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
add_compile_definitions(BX_CONFIG_DEBUG=1)
set(SOURCE "src/allocator.cpp"
"src/amalgamated.cpp"
"src/bounds.cpp"
"src/bx.cpp"
"src/commandline.cpp"
"src/crtnone.cpp"
"src/debug.cpp"
"src/dtoa.cpp"
"src/easing.cpp"
"src/file.cpp"
"src/filepath.cpp"
"src/hash.cpp"
"src/math.cpp"
"src/mutex.cpp"
"src/os.cpp"
"src/process.cpp"
"src/semaphore.cpp"
"src/settings.cpp"
"src/sort.cpp"
"src/string.cpp"
"src/thread.cpp"
"src/timer.cpp"
"src/url.cpp")
set(INLINE "include/bx/inline/allocator.inl"
"include/bx/inline/bounds.inl"
"include/bx/inline/bx.inl"
"include/bx/inline/cpu.inl"
"include/bx/inline/easing.inl"
"include/bx/inline/endian.inl"
"include/bx/inline/error.inl"
"include/bx/inline/float4x4_t.inl"
"include/bx/inline/handlealloc.inl"
"include/bx/inline/hash.inl"
"include/bx/inline/math.inl"
"include/bx/inline/mpscqueue.inl"
"include/bx/inline/mutex.inl"
"include/bx/inline/os.inl"
"include/bx/inline/pixelformat.inl"
"include/bx/inline/readerwriter.inl"
"include/bx/inline/ringbuffer.inl"
"include/bx/inline/rng.inl"
"include/bx/inline/simd128_langext.inl"
"include/bx/inline/simd128_neon.inl"
"include/bx/inline/simd128_ref.inl"
"include/bx/inline/simd128_sse.inl"
"include/bx/inline/simd128_swizzle.inl"
"include/bx/inline/simd256_avx.inl"
"include/bx/inline/simd256_ref.inl"
"include/bx/inline/simd_ni.inl"
"include/bx/inline/sort.inl"
"include/bx/inline/spscqueue.inl"
"include/bx/inline/string.inl"
"include/bx/inline/typetraits.inl"
"include/bx/inline/uint32_t.inl")
set(INCLUDE
"include/bx/allocator.hpp"
"include/bx/bounds.hpp"
"include/bx/bx.hpp"
"include/bx/commandline.hpp"
"include/bx/config.hpp"
"include/bx/constants.hpp"
"include/bx/cpu.hpp"
"include/bx/debug.hpp"
"include/bx/easing.hpp"
"include/bx/endian.hpp"
"include/bx/error.hpp"
"include/bx/file.hpp"
"include/bx/filepath.hpp"
"include/bx/float4x4_t.hpp"
"include/bx/handlealloc.hpp"
"include/bx/hash.hpp"
"include/bx/macros.hpp"
"include/bx/maputil.hpp"
"include/bx/math.hpp"
"include/bx/mpscqueue.hpp"
"include/bx/mutex.hpp"
"include/bx/os.hpp"
"include/bx/pixelformat.hpp"
"include/bx/platform.hpp"
"include/bx/process.hpp"
"include/bx/readerwriter.hpp"
"include/bx/ringbuffer.hpp"
"include/bx/rng.hpp"
"include/bx/semaphore.hpp"
"include/bx/settings.hpp"
"include/bx/simd_t.hpp"
"include/bx/sort.hpp"
"include/bx/spscqueue.hpp"
"include/bx/string.hpp"
"include/bx/thread.hpp"
"include/bx/timer.hpp"
"include/bx/typetraits.hpp"
"include/bx/uint32_t.hpp"
"include/bx/url.hpp"
"3rdparty/ini/ini.hpp"
)
if(WIN32)
if(MSVC)
set(INCLUDE ${INCLUDE}
    "include/compat/msvc/alloca.hpp"
    "include/compat/msvc/dirent.hpp"
    "include/compat/msvc/inttypes.hpp"
    "include/compat/msvc/stdbool.hpp")
elseif(MINGW)
    set(INCLUDE ${INCLUDE}
"include/compat/mingw/alloca.hpp"
"include/compat/mingw/dirent.hpp"
"include/compat/mingw/sal.hpp"
"include/compat/mingw/salieri.hpp"
"include/compat/mingw/specstrings_strict.hpp"
"include/compat/mingw/specstrings_undef.hpp")
endif()
elseif(NOT WIN32)
if(MINGW)
    set(INCLUDE ${INCLUDE}
    "include/compat/linux/sal.hpp"
    "include/compat/mingw/alloca.hpp"
    "include/compat/mingw/dirent.hpp"
    "include/compat/mingw/sal.hpp"
    "include/compat/mingw/salieri.hpp"
    "include/compat/mingw/specstrings_strict.hpp"
    "include/compat/mingw/specstrings_undef.hpp")
else()
    set(INCLUDE ${INCLUDE} "include/compat/linux/sal.hpp")
endif()
endif()
add_library(bx SHARED ${SOURCE} ${INLINE} ${INCLUDE})
target_include_directories(bx PUBLIC "src" "include" "include/bx" "3rdparty" "../bgfx/include" "../bimg/include")