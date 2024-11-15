#!/bin/sh
echo $@
g++ `wx-config --cxxflags` $@ main.cpp -o omenrgb `wx-config --libs`
