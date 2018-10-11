#!/bin/bash

path=$1

# Get a list of all directories
d=$(find $path -type d -print | wc -w | xargs)

# Get a list of all regular files
f=$(find $path -type f -print | wc -w | xargs)

# Print the results
printf "There were %d directories.\n" $d
printf "There were %d regular files.\n" $f
