#!/bin/bash

#This script compiles and test a variety of cache size's across the different cache positions
#output results to bcache.txt, ecache.txt, and mcache.txt

DIRECTORY="/run/media/manjaro/60a74a4a-05b1-4661-974b-a57d1de6fb3e/home/kurt/Documents/OSLab/proj3/project/"
STEPSIZE=1000
START=1000
END=50000
TRACKSIZE=4096
MAXBLOCK=17435426816

echo "Compiling"
g++ -std=c++11 -o bcache.exe $DIRECTORY/implementation/*.cpp $DIRECTORY/implementation/cacheLocs/cache_b.cpp
g++ -std=c++11 -o mcache.exe $DIRECTORY/implementation/*.cpp $DIRECTORY/implementation/cacheLocs/cache_m.cpp
g++ -std=c++11 -o ecache.exe $DIRECTORY/implementation/*.cpp $DIRECTORY/implementation/cacheLocs/cache_e.cpp

echo "Removing old results"
rm $DIRECTORY/results/*
touch $DIRECTORY/results/bcache.txt $DIRECTORY/results/mcache.txt $DIRECTORY/results/ecache.txt 

echo "Going from $START to $END by increments of $STEPSIZE"
while [ $START -lt $END ]
do
	echo "Testing Cache Size $START"
	$DIRECTORY/bcache.exe $TRACKSIZE $MAXBLOCK $START <$DIRECTORY/data/trace.txt >>$DIRECTORY/results/bcache.txt	
	$DIRECTORY/mcache.exe $TRACKSIZE $MAXBLOCK $START <$DIRECTORY/data/trace.txt >>$DIRECTORY/results/mcache.txt
	$DIRECTORY/ecache.exe $TRACKSIZE $MAXBLOCK $START <$DIRECTORY/data/trace.txt >>$DIRECTORY/results/ecache.txt
	let START=$START+$STEPSIZE
done
echo "Complete please view results/"
