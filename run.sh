#!/bin/bash

g++ main.cpp src/line_counter.hpp src/line_counter.cpp -std=c++17 -lpthread -lboost_system -o linecounter
./linecounter