#!/usr/bin/env bash

echo -e "\e[1;34mTest 0:\e[0;36m No arguments\e[0m"
./inrange

echo -e "\e[1;34mTest 1:\e[0;36m argv[1] invalid\e[0m"
echo -e "test\ntest\n12\n5\n23\n13" | ./inrange ab 19

echo -e "\e[1;34mTest 2:\e[0;36m argv[2] invalid\e[0m"
echo -e "test\ntest\n12\n5\n23\n13" | ./inrange 10 ab

echo -e "\e[1;34mTest 3:\e[0;36m \e[0m"
echo -e "test\ntest\n12\n5\n23\n13" | ./inrange  0 19

echo -e "\e[1;34mTest 4:\e[0;36m \e[0m"
echo -e "test\ntest\n12\n5\n23\n13" | ./inrange 10 19

# vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

