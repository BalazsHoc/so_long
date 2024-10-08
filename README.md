# About
![so_long_clip](https://github.com/user-attachments/assets/726faf5d-f12b-4299-935e-1cda3a023b3f)
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
