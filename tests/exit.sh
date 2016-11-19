#!/bin/sh
#NOTE: Built-in exit command will be called "Exit"

#TEST 1
Exit

#TEST 2
Exit ECHO abc

#TEST 3
ECHO abc Exit

#TEST 4
touch Exit

#TEST 5
ls Exit

#TEST 6
cat Exit

#TEST 7
Exit Exit Exit

#TEST 8
EXIT Exit

#TEST 9
Exit EXIT

#TEST 10
ECHO Exit