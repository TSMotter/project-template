#!/usr/bin/env bash

docker run --rm -it --platform linux/amd64 --workdir /builder/mnt -v .:/builder/mnt my-builder:latest /bin/bash