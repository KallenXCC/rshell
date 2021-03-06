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

###################
#ASSIGNMENT 3 TESTS
###################

#TEST 1
Exit ECHO Exit

#TEST 2
cat Exit

#TEST 3
(ECHO Initial || ECHO FAILED) && Exit

#TEST 4
Exit || Exit

#TEST 5
ECHO 1 && ECHO 2 && Exit && ECHO 4 && ECHO 5

#TEST 6
ECHO SUCCESSFUL || Exit || ECHO FAILED

#TEST 7
(Exit) || (ECHO FAILED)

#TEST 8
ls -a && Exit || ECHO FAILED ; ECHO DONE

#TEST 9
(Exit ; Exit) || ECHO SFAILED

#TEST 10
(ECHO testing Exit Command) && Exit || ECHO FAILED










