#!/bin/bash

echo "Clear folder..."
echo "Remove build/"

rm -rf build/

if [ ! -d "build" ]; then
	echo "Complete"
else
	echo "Fail"
fi




