#!/bin/bash

filesdir=$1
searchstr=$2

if [ -z $filesdir ] || [ -z $searchstr ]
then
    echo "Parameters not specified"
    exit 1
elif [ ! -d $filesdir ]
then
    echo "Not a File"
    exit 1
else
    X=$(find $filesdir -type f | wc -l)
    Y=$(grep -r -l $searchstr $filesdir | wc -l)
    echo "The number of files are $X and the number of matching lines are $Y"
fi

