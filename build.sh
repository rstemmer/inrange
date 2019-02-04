#!/usr/bin/env bash

TYPE="long long"

echo -e "\e[1;34mBuilding \e[0;36minrange\e[1;34m for data type \e[1;35m$TYPE\e[0m"
clang++ -std=c++17 -O3 -DxDEBUG -DTYPE="long long" -o inrange inrange.cpp
echo -e "\e[1;32mdone\e[0m"

# vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

