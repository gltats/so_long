# so_long
42 project  
A basic 2D computer graphics project developed using the MiniLibX library. The project is designed to help improve skills in window management, event handling, colors, textures and other computer graphics related areas.

## Status:
- Actual status: on-going
- Result :

## Requirements
- MiniLibX library (either the version available on the school machines or the one installed using its sources)
- Makefile for compiling the source files
- The program must take as parameter a map description file with .ber extension
- The program must use the open, close, read, write, malloc, free, perror, strerror and exit functions.
- All functions of the math library (-lm compiler option, man man 3 math)
- All functions of the MiniLibX
- ft_printf and any equivalent functions you have coded
- Libft authorized

## Game
- The player's goal is to collect all collectibles present on the map and escape using the shortest possible route
- The W, A, S, and D keys or the ZQSD or arrow keys must be used to move the main character
- The player can move in 4 directions: up, down, left, right
- The player cannot move into walls
- The current number of movements must be displayed in the shell at every move
- The game must use a 2D view (top-down or profile)
- The game does not have to be real-time

## Graphic Management
- The program must display the image in a window
- The window management must remain smooth even when changing to another window or minimizing
- Pressing ESC must close the window and quit the program in a clean way
- Closing the window by clicking the cross on the frame must close the window and quit the program in a clean way
- The images of the MiniLibX must be used

## Map

The map must be constructed with 3 components: walls, collectibles, and free space
The map can only be composed of 5 characters:
    0 for an empty space
    1 for a wall
    C for a collectible
    E for a map exit
    P for the player's starting position
The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid
The map must not contain duplicates characters (exit/start)
The map must be rectangular
The map must be closed/surrounded by walls. If it's not, the program must return an error
The program must check if there's a valid path in the map
The program must be able to parse any kind of map, as long as it follows the rules stated above

## Error Handling
If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way and return "Error\n" followed by an explicit error message of your choice.
