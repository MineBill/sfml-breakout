#!/bin/bash

if [[ ! -L ./compile_commands.json ]]; then
    ln -s ./Debug/compile_commands.json ./compile_commands.json
fi
