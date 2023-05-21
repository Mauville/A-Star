# A* Shortest Path Finder

This program computes the shortest path between two cities in France using the A* algorithm. It takes the names of the departure and arrival cities as input and displays the complete shortest path, along with partial distances for each intermediate city and the total distance for the trip.

## How to Use

To run the program, open a terminal and execute the following command:

`$ ./aStar [departure city] [arrival city]`

Replace `[departure city]` with the name of the city from which you want to start your journey, and `[arrival city]` with the name of the city you wish to reach.

The program will compute the shortest path between the specified cities and display the result on the terminal.

## Example Usage

Here's an example of how the program should be called and the expected output:

```
$ ./aStar Rennes Lyon
Rennes: (0 km)
Nantes: (107 km)
Limoges: (436 km)
Lyon: (825 km)
```

## Team Members

- Oscar VARGAS PEREZ
- Obbina DONATUS
