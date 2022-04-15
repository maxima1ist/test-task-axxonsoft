#!/bin/bash

g++ main.cpp -std=c++17 -lpthread -lboost_system -o linecounter
./linecounter