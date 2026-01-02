#!/bin/bash

writefile=$1
writestr=$2

if [ -z $writefile ] || [ -z $writestr ]
then
    echo "Parameters not specified"
    exit 1
fi

dirpath=$(dirname $writefile)
mkdir -p $dirpath || {
    echo "Directory could not be created"
    exit 1
}

echo $writestr > $writefile || {
    echo "File Could not be created"
    exit 1
}