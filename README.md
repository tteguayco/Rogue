# Rogue

Introduction
============

This game has been developed using the C++ object-oriented programming language as a part of a practical work for the
'Computability and Algorithms' subject.

![Image Rogue](https://github.com/tteguayco/Rogue/blob/master/prototype/Captura%20de%20pantalla%20de%202017-07-09%2017-33-27.png?raw=true)

Description
===========

Initially, the player is set in one of the three rooms of a dungeon with 5 lives. There are three monsters in each room so, 
if the player is caught by one of them, will lose a life. Furthermore, all of the rooms are connected together by a corridor, 
where the monsters cannot access to.

The goal of the game is to get an amulet which is placed in another room and come back to the access point (the starter position
for the player).

Notation
========

The game is shown in plain text from a terminal. Because of it, a specific notation has been adopted in order to display the different
elements which are presented in the environment:

* __*__: wall of a room
* __+__: door of a room
* __#__: cell of a corridor
* __@__: player
* __X__: access point
* __&__: amulet
* __O__: monster

Building
========

From a shell, build an binary file to be placed in the bin/ directory using the Make tool:
```sh
make
```

To run the generated binary file, just run the following:
```sh
./bin/rogue
```
