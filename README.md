# About
![so_long](https://github.com/user-attachments/assets/121f2eee-d0b2-4966-adbd-3266b0f13e98)
## Introduction
In this project, we'll code a simple 2D game to get familiar with the mlx library and UI in general. In my case, it's Mario.

## Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- Only ``P`` *(player)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectable)*, and ``E`` *(exit)* will be accepted characters in our map
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game must end with ``Error\n`` followed by a custom message.

The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps
