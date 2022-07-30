#! /bin/bash
HOMEDIR=build/
HOMEDIRDOC=docs/
mkdir build/usr/share/man -p
mkdir -p ../build/usr/share/man/
LIST_COMMAND='ftdos'
echo Generate hlp
for I in $LIST_COMMAND; do
echo Generate $I
cat $HOMEDIRDOC/$I.md | ../md2hlp/src/md2hlp.py3 -c docs/md2hlp.cfg > build/usr/share/man/$I.hlp
done
