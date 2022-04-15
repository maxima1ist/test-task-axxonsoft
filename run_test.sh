#!/bin/bash

g++ test.cpp src/line_counter.hpp src/line_counter.cpp -std=c++17 -lpthread -lboost_system -lgtest -o testsrunner
./testsrunner