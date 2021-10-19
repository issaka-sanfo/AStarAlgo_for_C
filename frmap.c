/*********************************************************************************
* Map Fonctions and Procedures Definition file by Issaka SANFO - EPITA/SE        *
*********************************************************************************/



//Includes of head of files and libraries
#include <stdio.h>
#include "frmap.h"
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include"status.h"



// insert neighbors, called when inserting a city

void insertNeighbor(struct listneighbor **head,char nameneighbor[50] ,int distance){
    struct listneighbor *temp,*current;
    temp=malloc(sizeof(struct listneighbor));
    strcpy(temp->nameneighbor, nameneighbor);
    temp->distneibor=distance;
    temp->nextneighbor=NULL;

    if((*head)==NULL){
        (*head)=temp;
    }
    else{
        current=(*head);
        while(current->nextneighbor!=NULL){
            current=current->nextneighbor;
        }
        current->nextneighbor=temp;
    }
}




//  insert list of cities
void insertCity(struct listcity **Listhead,struct listneighbor *head, char namecity[50], int coord_x, int coord_y){
    struct listcity *temp,*current;
    temp=malloc(sizeof(struct listcity));
    strcpy(temp->namecity, namecity);
    temp->coord_x = coord_x;
    temp->coord_y = coord_y;
    temp->startneighbor = head;
    temp->nextcity=NULL;
    if((*Listhead)==NULL){
        (*Listhead)=temp;
    }
    else{
        current=(*Listhead);
        while(current->nextcity!=NULL){
            current=current->nextcity;
        }
        current->nextcity=temp;
    }
}

//Insert Sequence of best Neighbors
void insertResult(struct listitinerary **head,char nameneighbor[50] ,int distance){
    struct listitinerary *temp,*current;
    temp=malloc(sizeof(struct listitinerary));
    strcpy(temp->nameneighbor, nameneighbor);
    temp->distneibor=distance;
    temp->nextneighbor=NULL;

    if((*head)==NULL){
        (*head)=temp;
    }
    else{
        current=(*head);
        while(current->nextneighbor!=NULL){
            current=current->nextneighbor;
        }
        current->nextneighbor=temp;
    }
}

//Show Result of best Sequence of Cities from Stat City to Goal City
void showResult(struct listitinerary *Listresult){
    struct listitinerary *currentneighb;
    currentneighb=Listresult;
    while(currentneighb!=NULL){
        printf("%s \t",currentneighb->nameneighbor);
        printf("%d \n",currentneighb->distneibor);
        currentneighb=currentneighb->nextneighbor;
    }
    printf("\n");
}

//For Test I used this function to Show the list of cities
void showCities(struct listcity *Listhead){
    struct listcity *currentcity;
    struct listneighbor *currentneighb;
    currentcity=Listhead;
    while(currentcity!=NULL){  ////////////////////////////////////Loop for cities
        currentneighb=currentcity->startneighbor;
        printf("%s \t %d \t %d \n",currentcity->namecity,currentcity->coord_x,currentcity->coord_y);
        while(currentneighb!=NULL){        ////////////////////////////////////Loop for city Neighbors
            printf("%s \t",currentneighb->nameneighbor);
            printf("%d \n",currentneighb->distneibor);
            currentneighb=currentneighb->nextneighbor;
        }
        printf("\n");
        currentcity=currentcity->nextcity;
    }
}

//Free list of Neighbors
void freeNeighbors(struct listneighbor* head)
{
   struct listneighbor* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->nextneighbor;
       free(tmp);
    }

}


//Free list of Cities
void freeCities(struct listcity* Listhead)
{
   struct listcity* tmp;

   while (Listhead != NULL)
    {
       tmp = Listhead;
       Listhead = Listhead->nextcity;
       free(tmp);
    }

}

//Free list of Result Sequences for memory optimization
void freeResult(struct listitinerary* head)
{
   struct listitinerary* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->nextneighbor;
       free(tmp);
    }

}


//Find Coordinates of a Neighbor by using its name, this function help to use Neighbor coordinates for the Calculs
struct listcity* findCityCoor(struct listcity* Listhead, char nameneighb[50]){
    struct listcity *currentcity;
    currentcity=Listhead;
    while(currentcity!=NULL){
        if(strcmp(currentcity->namecity,nameneighb)==0){
            return currentcity;
        }
        currentcity=currentcity->nextcity;
    }
    return NULL;
}


// Variable to keep the result sequence of cities
struct listitinerary* res=NULL;

//Function to find the Best neighbor in the list of current neighbors
struct listneighbor* findShortNeighbor(struct listcity* Listhead, struct listcity* firstCity, struct listcity* finalDest){

    struct listneighbor *currentneighb = firstCity->startneighbor;
    struct listneighbor *currentneighb2 = firstCity->startneighbor;

    double bestDist;

    //This variable will take result of the distance Between the current Neighbor and the Destination city
    bestDist = sqrt(pow(findCityCoor(Listhead,firstCity->startneighbor->nameneighbor)->coord_x - (finalDest->coord_x), 2) +
                    pow(findCityCoor(Listhead,firstCity->startneighbor->nameneighbor)->coord_y - (finalDest->coord_y), 2));


    if(strcmp(currentneighb->nameneighbor,finalDest->namecity)==0){
            insertResult(&res,currentneighb->nameneighbor,currentneighb->distneibor);
            return currentneighb;
            //return 0;
    }else{
        while(currentneighb!=NULL){

            if(strcmp(currentneighb->nameneighbor,finalDest->namecity)==0){
                insertResult(&res,currentneighb->nameneighbor,currentneighb->distneibor);
                return currentneighb;
                //return 0;
            }

            //When a short distance is found in the neighbors the variable take it
            if(bestDist > sqrt(pow(findCityCoor(Listhead,currentneighb->nameneighbor)->coord_x - (finalDest->coord_x), 2) +
                               pow(findCityCoor(Listhead,currentneighb->nameneighbor)->coord_y - (finalDest->coord_y), 2))){
                bestDist = sqrt(pow(findCityCoor(Listhead,currentneighb->nameneighbor)->coord_x - (finalDest->coord_x), 2) +
                                pow(findCityCoor(Listhead,currentneighb->nameneighbor)->coord_y - (finalDest->coord_y), 2));
            }
            currentneighb=currentneighb->nextneighbor;
        }

        while(currentneighb2!=NULL){
            //And I insert this neighbors in the best sequence and I return it
            if(sqrt(pow(findCityCoor(Listhead,currentneighb2->nameneighbor)->coord_x - (finalDest->coord_x), 2) +
                        pow(findCityCoor(Listhead,currentneighb2->nameneighbor)->coord_y - (finalDest->coord_y), 2)) == bestDist){
                insertResult(&res,currentneighb2->nameneighbor,currentneighb2->distneibor);
                return currentneighb2;
                //return 0;
            }
            currentneighb2=currentneighb2->nextneighbor;
        }
    }

    return NULL;
}


//Here I take the input and show the result
void listresult(char start[50], char goal[50], struct listcity* Listhead){

    struct listcity* startCity = findCityCoor(Listhead,start);
    struct listcity* goalCity = findCityCoor(Listhead,goal);
    if(startCity == NULL)
    {
        printf("%s", message(ERRNAMESTART));
    }

    if(goalCity == NULL)
    {
        printf("%s", message(ERRNAMEDEST));
    }

    struct listcity* currentListCity = startCity;
        while(strcmp(currentListCity->namecity,goalCity->namecity)!=0){//To loop in the Whole Cities based on short neighbor each time
            currentListCity = findCityCoor(Listhead,findShortNeighbor(Listhead,currentListCity,goalCity)->nameneighbor);
        }
    showResult(res);//Show best Itinerary
    freeResult(res);//Free Result
};
