***************************************************
# Sanke_SDL_CPP 
Snake_SDL_CPP is an opensource 2D game created using SDL1.2 and CPP.
## Source code compilation:
* First install required libraries:
```
libsdl1.2, libsdl-mixer1.2, libsdl-ttf2.0
``` 
* For debian distribution and derivates:
```
apt-get install libsdl1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev
```
* Compile the source code:
```
g++ main.cpp snake.cpp node.cpp -lSDL -lSDL_mixer -lSDL_ttf
```

## using cmake
```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=${PWD} ..
make
make install
```

## using Nix
```
nix-build
```
\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*ENJOY\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*
