#!/bin/sh
#TEST 1
[ -e test/rshell/rshell ]

#TEST 2
[ -e test/main.cpp/rshell/src ]

#TEST 3
test -f test/Command.cpp/rshell

#TEST 4
test -f test/Command.h/rhsell/src

#TEST 5
test -d test/rshell/rshell

#TEST 6
test -d test/tests/tests

#TEST 7
test -e test/exit.sh/rshell/tests -f test/LICENSE/rhsell/header

#TEST 8
[ -f test/AndAnd.cpp/rshell ] 

#TEST 9
[ -d test/Base.h/rshell/header]

#TEST 10
test -e test/Flag.h/rshell/src -f test/README.md/rhsell -d test/Oror.o/rshell/src