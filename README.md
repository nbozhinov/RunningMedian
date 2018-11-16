# Running Median

[![Build Status](https://travis-ci.com/nbozhinov/RunningMedian.svg?branch=master)](https://travis-ci.com/nbozhinov/RunningMedian)
[![codecov](https://codecov.io/gh/nbozhinov/RunningMedian/branch/master/graph/badge.svg)](https://codecov.io/gh/nbozhinov/RunningMedian)
[![License: Unlicense](https://img.shields.io/badge/license-Unlicense-blue.svg)](http://unlicense.org/)

A solution for an interview task. And an opportunity to test Travis CI.  

Contains a header-only library for finding the median of a set of numbers.  
The two supported operations are adding new number and extracting the median.  
Using two heaps to ensure minimal time complexity for adding new number and for
extracting the median.  

## Building & testing with CMake  
(see also "build.bat" or "./build.sh")  

mkdir build  
cd build  
cmake ..                         # cmake .. -G "Visual Studio 15"    # for Visual Studio 2017  
cmake --build . --config Release # make  
ctest . -C Release               # make test  

## Unit tests using Catch 2
The code is tested by unit test using the Catch header-only library version 2.4.2.
The code for the tests is in the "tests" directory (obviously), along with a copy of Catch.

## Continuous Integration

This project is continuously tested under Ubuntu Linux with the gcc and clang compilers
using the Travis CI community service (https://travis-ci.com/) with the above CMake building
and testing procedure. Windows builds on Travis CI are still experimental and unsatable, so
they are commented out form the travis configuration.

Code coverage from the unit tests is checked by Codecov (https://codecov.io/).  

Detailed results can be seen online:  
https://travis-ci.com/nbozhinov/RunningMedian and https://codecov.io/gh/nbozhinov/RunningMedian

## Contents  
* [include](include/) the directory with the header (and only file) of the library.
* [include/running_median.h](include/running_median.h) the header containing the library.
* [tests](tests) the directory with the unit tests for the library.
* [tests/tests_manual.cpp](tests/tests_manual.cpp) test case with manualy generated data.
* [tests/tests_randomized.cpp](tests/tests_randomized.cpp) test case with randomly generated data.
* [tests/catch_2.4.2/catch.hpp](tests/catch_2.4.2/catch.hpp) A copy of [Catch](https://github.com/catchorg/Catch2) used for the unitests.
* CMakeLists.txt the cmake files for building and testing the project.
* [.travis.yml](.travis.yml) the configuration for Travis CI used for automated building and testing
* [.codecov.yml](.codecov.yml) the configuration for CodeCov used for calculating the code coverage of the tests.
* [build.bat](build.bat) and [build.sh](build.sh) simple scripts used for easier manual building.

## License

This project is licensed under the Unlicense License - see the [UNLICENSE](UNLICENSE) file for details.  
(Just so I can have the cool looking badge)