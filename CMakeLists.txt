# 1. Tentukan versi minimal CMake
cmake_minimum_required(VERSION 3.15)

# 2. Nama Proyek dan Bahasa
project(OpenCV_Learning VERSION 1.0 LANGUAGES CXX)

# 3. Set Standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 4. Cari Library OpenCV
find_package(OpenCV REQUIRED)

# 5. Tampilkan Informasi OpenCV yang Ditemukan (Untuk Debugging)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# 6. Tambahkan File Executable (Main Program)
add_executable(app src/main.cpp)

# 7. Hubungkan Header OpenCV ke Target
target_include_directories(app PRIVATE ${OpenCV_INCLUDE_DIRS})

# 8. Link Library OpenCV ke Executable
target_link_libraries(app PRIVATE ${OpenCV_LIBS})