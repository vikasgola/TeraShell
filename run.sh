#!/bin/bash

g++ -std=c++11 src/shell.cpp -o dist/shell
rlwrap  --complete-filenames dist/shell