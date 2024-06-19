#!/bin/bash

cmake.
make
./main task1> ./result/task1_image.ppm
./main task2> ./result/task2_image.ppm
./main task3> ./result/task3_image.ppm

