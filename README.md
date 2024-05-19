# Baba is You - Simplified C++ Implementation

This project is a re-creation of the game "Baba is You" in C++.

This README will explain the game rules and gameplay to help you better understand our project. It will also list known bugs, provide justifications for any warnings, and suggest possible improvements.

## Game Rules
The various game rules are:
- **SINK**: Kills the player and destroys the rock and itself if a rock passes over it.
- **PUSH**: Moves in the direction of the player's movement if the player moves towards it upon contact.
- **YOU**: The element associated with this rule is the player and moves according to the given commands.
- **STOP**: Blocks the movement of the player or any other object trying to pass through.
- **WIN**: The player wins if they reach an element with this rule.
- **KILL**: Kills the player if they step on an element containing this rule.

## Gameplay
The player must try to reach one of the objects containing the WIN rule. To do this, they can move objects and modify the rules.

All rule elements (TEXT_ELEMENT, IS, RULE (*see "Game Rules" section*)) are movable by default.

All elements that are not rule elements are passable by default.

For a rule to be valid, it must consist of three ordered elements: a TEXT_ELEMENT followed by an IS, followed by a RULE. If any of these elements are missing or not in the correct order, the rule is not applied.

A rule is not permanent; once broken down, it is no longer applied.

A rule applies only to elements of the type of the corresponding TEXT_ELEMENT.

## Known Bugs
When placing an object on an object with the KILL rule, and that object does not have the YOU rule, the object does not die (which is normal). However, when changing the rule to give the YOU rule to the object that is already on an object with the KILL rule, it does not die.

