#!/bin/bash

# TODO: Check whether env variables are set

# TODO: give full path; using the alias is dangerous!

# TODO: check include flag! Important!

$HPHP_HOME/src/hphp/hphp \
	--input-dir ./in \
	--output-dir ./out \
	--keep-tempdir 1 \
	--log 4 
