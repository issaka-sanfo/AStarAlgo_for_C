/********************************************************************************
* Map Fonctions and Procedures Declarartion file by Issaka SANFO - EPITA/SE     *
*********************************************************************************/




//Includes of head of files
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"status.h"




//List of neighbours
typedef struct listneighbor{
    char nameneighbor[50]; //Name of the neighbour city
    int distneibor; //Distance between the current city and this neibour
    struct listneighbor *nextneighbor; //this points the neighbour in the list
}listneighbor;

//List of cities
typedef struct listcity{
    char namecity[50]; //Name of the city
    int coord_x; //First coordinate
    int coord_y; //Second coordinate
    struct listneighbor *startneighbor;//This ponits to the first neighbor in the City neighbors
    struct listcity *nextcity;//Points to the next city in the list
}listcity;

//List to handle best itinerary neighbors
typedef struct listitinerary{
    char nameneighbor[50]; //Name of the best neighbor city
    int distneibor; //Distance between the current city and this neibour
    struct listitinerary *nextneighbor; //Points to the next best Neighbor
}listitinerary;


//Declaration of function to insert list of Each list of Neighbor from the file to the List of Neighbors
void insertNeighbor(struct listneighbor **head,char nameneighbor[50] ,int distance);

//Declaration of function to insert all cities from the file to the List of Cities, and point for each city to its beighbors
void insertCity(struct listcity **Listhead,struct listneighbor *head, char namecity[50], int coord_x, int coord_y);

//Declaration of function to insert all best Neighbor found
void insertResult(struct listitinerary **head,char nameneighbor[50] ,int distance);

//Declaration of function to Test if I handle the whole list of cities and their neighbors properly
void showCities(struct listcity *Listhead);

//Declaration of function to free list of neighbors at the end of the program
void freeNeighbors(struct listneighbor* head);

//Declaration of function to free list of cities at the end of the program
void freeCities(struct listcity* Listhead);

//Declaration of function to free list of result sequence
void freeResult(struct listitinerary* head);

//Declaration of function to find Coordinates of a Neighbor
struct listcity* findCityCoor(struct listcity* Listhead, char nameneighb[50]);

//Declaration of function to find the best Neighbor to go to goal city
struct listneighbor* findShortNeighbor(struct listcity* Listhead, struct listcity* firstCity, struct listcity* finalDest);

//Declaration of function to list the Result of Sequence of Cities with short path
void listresult(char start[50], char goal[50], struct listcity* Listhead);
