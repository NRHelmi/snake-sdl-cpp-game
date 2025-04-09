{ pkgs ? import <nixpkgs> {}}:

with pkgs; stdenv.mkDerivation rec {
  name = "snake-game-${version}";
  version = "0.0.1";
  src = ./.;

  nativeBuildInputs = [
    cmake
    libgcc
  ];

  buildInputs = [
    SDL
    SDL_mixer
    SDL_ttf
  ];
}
