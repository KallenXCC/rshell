#!/bin/sh
#TEST 1
ls -a; ECHO hello world && ECHO world hello || ECHO world world && ECHO hello hello

#TEST 2
&& touch README.md && Exit && ECHO FAIL

#TEST 3
ls -l || ls -a || ls -a || ls -l

#TEST 4
ECHO 1; ECHO 2; ECHO 3; ECHO 4; ECHO 5; ECHO 6; ECHO 7; ECHO 8; ECHO 9; ECHO 10

#TEST 5
ECHO HELLO && || ; && || ; ECHO WORLD

#TEST 6
&& || ; || ; && ; ; || || && || && ;

#TEST 7
ECHO TIME: && date || ECHO FAILED

#TEST 8
ECHO HELLO      &&      ECHO WORLD

#TEST 9
touch README.md && cat README.md || ECHO FAILED || ECHO TRY AGAIN && Exit

#TEST 10
mkdir test && rmdir test || man --help || help