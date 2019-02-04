#!/usr/bin/env bash

PREFIX=/usr/local

echo -e "inrange  Copyright (C) 2019  Ralf Stemmer <ralf.stemmer@gmx.net>"
echo -e "This program comes with \e[1;33mABSOLUTELY NO WARRANTY\e[0m."
echo -e "This is free software, and you are welcome to redistribute it"
echo -e "under certain conditions.\n"

install -m 755 -s -v -g root -o root inrange   -D $PREFIX/bin/inrange
install -m 644    -v -g root -o root inrange.1 -D $PREFIX/share/man/man1/inrange.1


# vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

