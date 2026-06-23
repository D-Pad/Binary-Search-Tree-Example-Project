#!/bin/bash 


# Build script to compile and run the project
[[ ! -d "./build" ]] && mkdir build
[[ ! -d "./bin" ]] && mkdir bin
cd ./build
cmake ..
if make; then 
    execName=$(cmake --build . | awk '{print $NF}')
    mv $execName ../bin/$execName
    echo -ne "\e[H\e[2J" 
    cd ../bin
    ./$execName
else 
    echo -e "\e[1;31mCompilation failed...\e[0m"
fi


