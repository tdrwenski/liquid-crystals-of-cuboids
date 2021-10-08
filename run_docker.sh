#!/bin/bash

if [[ -z $1 ]]; then
    echo "No argument was supplied. Using example input file"
    export inputFile=config_cuboid.txt
else
    inputFile=$1
fi

docker run -it --rm -v $(pwd)/input:/cuboids/input \
    -v $(pwd)/results:/cuboids/results \
    --name cuboids cuboids ./run $inputFile
