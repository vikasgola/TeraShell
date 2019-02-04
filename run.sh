#!/bin/bash

g++ -std=c++11 src/shell.cpp -o bin/shell
rlwrap  --complete-filenames bin/shell