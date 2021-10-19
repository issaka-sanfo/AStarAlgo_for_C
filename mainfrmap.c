/*******************************************
* Main file by Issaka SANFO - EPITA/SE     *
*******************************************/


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

//Includes of head of files and libraries
#include <stdio.h>
#include <stdlib.h>
#include "frmap.h"
#include<string.h>
#include"status.h"


//Here I can take Input from CMD or ask the user to Enter the names of Source and Destination Cities

int main(int nwords,char*words[])
{

    if(nwords < 3 || nwords > 3){
        printf("%s",message(ERRPARAM));//I Show the Parametters Error Message from "Status" defined
        exit(1);
    }


    char startcity[20], destincity[20];
    strcpy(startcity,words[1]);
    strcpy(destincity,words[2]);
    printf("\n********Hi Sir, Welcome To Short Path of cities Calculator*********\n\n\n");





    printf("\n");//Go at new line
    //The program start by opening the FRANCE.MAP file to read the content and put in Chained list
    FILE *fp;
    char name[50];
    int x,y;

    fp = fopen("FRANCE.MAP", "r");

    if(fp == NULL)//If opening fail, Show an Error message
    {
        printf("%s",message(ERROPEN));//I Show the opening Error Message from "Status" defined
        exit(1);
    }



    int i=0;//For loop in file
    int j=0;//For loop in file

    //As we have 19 Cities, I made 19 List of neighbours for each city
    struct listneighbor *head1=NULL; //lists of Neighbours
    struct listneighbor *head2=NULL; //lists of Neighbours
    struct listneighbor *head3=NULL; //lists of Neighbours
    struct listneighbor *head4=NULL; //lists of Neighbours
    struct listneighbor *head5=NULL; //lists of Neighbours
    struct listneighbor *head6=NULL; //lists of Neighbours
    struct listneighbor *head7=NULL; //lists of Neighbours
    struct listneighbor *head8=NULL; //lists of Neighbours
    struct listneighbor *head9=NULL; //lists of Neighbours
    struct listneighbor *head10=NULL; //lists of Neighbours
    struct listneighbor *head11=NULL; //lists of Neighbours
    struct listneighbor *head12=NULL; //lists of Neighbours
    struct listneighbor *head13=NULL; //lists of Neighbours
    struct listneighbor *head14=NULL; //lists of Neighbours
    struct listneighbor *head15=NULL; //lists of Neighbours
    struct listneighbor *head16=NULL; //lists of Neighbours
    struct listneighbor *head17=NULL; //lists of Neighbours
    struct listneighbor *head18=NULL; //lists of Neighbours
    struct listneighbor *head19=NULL; //lists of Neighbours

    struct listcity *Listhead=NULL;  // Listhead will be the head of lists of cities

    while( fscanf(fp, "%s%d%d"
                    , name, &x, &y) != EOF )//Read Neighbors
    {

        if(i>0 && i<4){
            insertNeighbor(&head1,name,x);
        }
        if(i>4 && i<8){
            insertNeighbor(&head2,name,x);
        }
        if(i>8 && i<10){
            insertNeighbor(&head3,name,x);
        }
        if(i>10 && i<15){
            insertNeighbor(&head4,name,x);
        }
        if(i>15 && i<22){
            insertNeighbor(&head5,name,x);
        }
        if(i>22 && i<27){
            insertNeighbor(&head6,name,x);
        }
        if(i>27 && i<30){
            insertNeighbor(&head7,name,x);
        }
        if(i>30 && i<34){
            insertNeighbor(&head8,name,x);
        }
        if(i>34 && i<39){
            insertNeighbor(&head9,name,x);
        }
        if(i>39 && i<45){
            insertNeighbor(&head10,name,x);
        }
        if(i>45 && i<50){
            insertNeighbor(&head11,name,x);
        }
        if(i>50 && i<53){
            insertNeighbor(&head12,name,x);
        }
        if(i>53 && i<57){
            insertNeighbor(&head13,name,x);
        }
        if(i>57 && i<61){
            insertNeighbor(&head14,name,x);
        }
        if(i>61 && i<64){
            insertNeighbor(&head15,name,x);
        }
        if(i>64 && i<69){
            insertNeighbor(&head16,name,x);
        }
        if(i>69 && i<72){
            insertNeighbor(&head17,name,x);
        }
        if(i>72 && i<75){
            insertNeighbor(&head18,name,x);
        }
        if(i>75 && i<77){
            insertNeighbor(&head19,name,x);

        }

        i++;//Increment to go to the next City

    }

    fclose(fp);

    FILE *fp2;
    fp2 = fopen("FRANCE.MAP", "r");

    if(fp2 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while( fscanf(fp2, "%s%d%d"
                    , name, &x, &y) != EOF )//Read Cities
    {
        if(j==0){
            insertCity(&Listhead,head1,name,x,y);
        }
        if(j==4){
            insertCity(&Listhead,head2,name,x,y);
        }
        if(j==8){
            insertCity(&Listhead,head3,name,x,y);
        }
        if(j==10){
            insertCity(&Listhead,head4,name,x,y);
        }
        if(j==15){
            insertCity(&Listhead,head5,name,x,y);
        }
        if(j==22){
            insertCity(&Listhead,head6,name,x,y);
        }
        if(j==27){
            insertCity(&Listhead,head7,name,x,y);
        }
        if(j==30){
            insertCity(&Listhead,head8,name,x,y);
        }
        if(j==34){
            insertCity(&Listhead,head9,name,x,y);
        }
        if(j==39){
            insertCity(&Listhead,head10,name,x,y);
        }
        if(j==45){
            insertCity(&Listhead,head11,name,x,y);
        }
        if(j==50){
            insertCity(&Listhead,head12,name,x,y);
        }
        if(j==53){
            insertCity(&Listhead,head13,name,x,y);
        }
        if(j==57){
            insertCity(&Listhead,head14,name,x,y);
        }
        if(j==61){
            insertCity(&Listhead,head15,name,x,y);
        }
        if(j==64){
            insertCity(&Listhead,head16,name,x,y);
        }
        if(j==69){
            insertCity(&Listhead,head17,name,x,y);
        }
        if(j==72){
            insertCity(&Listhead,head18,name,x,y);
        }
        if(j==75){
            insertCity(&Listhead,head19,name,x,y);
        }

        j++;
    }
    fclose(fp2);





    printf("To go from 1. %s to 2. %s, the best sequences of cities is below:\n", startcity, destincity);

    listresult(words[1], words[2], Listhead);

    printf("END//////////////////////////////////////////////////////////////END");


    //Free the cities
    freeCities(Listhead);

    /*Free Each list of Neighbors*/
    freeNeighbors(head1);
    freeNeighbors(head2);
    freeNeighbors(head3);
    freeNeighbors(head4);
    freeNeighbors(head5);
    freeNeighbors(head6);
    freeNeighbors(head7);
    freeNeighbors(head8);
    freeNeighbors(head9);
    freeNeighbors(head10);
    freeNeighbors(head11);
    freeNeighbors(head12);
    freeNeighbors(head13);
    freeNeighbors(head14);
    freeNeighbors(head15);
    freeNeighbors(head16);
    freeNeighbors(head17);
    freeNeighbors(head18);
    freeNeighbors(head19);

    return 0;

}

