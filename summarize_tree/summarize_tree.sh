#!/bin/bash

path=$1

# Get the number of directories
d=$(find $path -type d -print | wc -w | xargs)

# Get the number of regular files
f=$(find $path -type f -print | wc -w | xargs)

# Print the results
printf "There were %d directories.\n" $d
printf "There were %d regular files.\n" $f
