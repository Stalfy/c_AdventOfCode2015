#!/bin/bash
make test

echo ""
echo ">>>"

./aoc2015
isTestPassed=$?

echo "<<<"
echo ""

if [ 0 -eq $isTestPassed ]; then
    make all

    echo ""
    echo ">>>"

    ./aoc2015 $1

    echo "<<<"
    echo ""
fi

make clean
