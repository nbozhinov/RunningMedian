mkdir build
cd build
cmake .. -G "Visual Studio 15"
cmake --build . --config Release
ctest . -C Release
