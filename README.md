# Conveyor Belt and Delivery Trucks Simulation (C++)

This is a console-based simulation of a conveyor belt system that loads generated items into delivery trucks. The project demonstrates queue and stack manipulation in C++, simulating logistics and space management.

### Project Description

- A conveyor belt continuously generates items (random weights between 0.1 and 10.0).

- Each item is removed from the conveyor and considered for loading into a fleet of trucks.

- Trucks have a limited capacity (randomized between 12–21 units).

- Each truck's content is stored as a stack (LIFO) of item weights.

- If no existing truck can carry the item, a new truck is added to the fleet.

- Visual display of:

  - The conveyor belt queue

  - The current item being processed

  - The contents of all trucks

  - The truck number, total capacity, and current load
