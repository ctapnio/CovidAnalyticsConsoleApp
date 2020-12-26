/* Covid Analytics
 * Created by: Christian Tapnio 2020-11-05
 * C program to store, analyze and update Covid-19 information about Greater Toronto Area
 * (GTA) for the health ministry of Ontario
 * Implementation file
 * */
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//String arrays to be used for referencing enums as strings- To be defined in implementation file to avoid duplicate symbol error
const char *races[] = {"Caucasian","Indigenous","AfricanAmerican","Asian","Other"};
const char *regions[] = {"Peel", "York", "Durham"};
const char *towns[] = {"Brampton", "Mississauga", "Maple", "Vaughan", "Whitby", "Oshawa"};

//random number generator function
int generateRand(int min, int max) {
    int result;
    result = (rand() % (max - min + 1)) + min;
    return result;
}//end of generateRand function

//Used for validating user input
int inputValidator(int min, int max) {
    int value = ROGUE_VAL;
    while (value == ROGUE_VAL){
        if (scanf(" %d", &value) == 1 && value >= min && value <= max) {
            return value;
        } else {
            value = ROGUE_VAL;
            printf("Invalid data. You should enter one integer in the range of %d "
                   "to %d. Please try again\n", min, max);
        }//end of if else statement
    }//end of while loop
}//inputValidator function ends

//checks if LinkedList is empty
int isEmpty(Household* ptr){
    return (ptr == NULL);
}//end of isEmpty function

//prints all household records in a LinkedList
void printAll(Household* ptr){
    if(isEmpty(ptr)){
        puts("This is an empty list");
        return;
    }
    //Reading through LinkedList
    int counter = 0;
    puts("S.no\tSize\tTotal tested\tTotal tested positive\t\t\tRace\t\tRegion\t\t\tTown");
    while (ptr != NULL){
        counter++;
        printf("%d\t%7d\t%10d\t%18d\t%24s\t%10s\t%12s\n", counter, ptr->numberOfPeople, ptr->totalTested
                , ptr->totalPositive, races[ptr->raceName], regions[ptr->regionName], towns[ptr->townName]);
        ptr = ptr->next;
    }//end of while loop
    puts("");
}//end of printAll function

//prints records with a specified region
void printByRegion(Household* ptr){
    if(isEmpty(ptr)){
        puts("This is an empty list");
        return;
    }
    int counter = 0;
    int region;
    puts("Enter an integer for region: Peel(0), York(1) and Durham (2):");
    region = inputValidator(0, 2) ;
    printf("Records with region: %s\n", regions[region]);
    puts("S.no\tSize\tTotal tested\tTotal tested positive\t\t\tRace\t\tRegion\t\t\tTown");
    while (ptr != NULL ){
        counter++;
        if (region == ptr->regionName){
            printf("%d\t%7d\t%10d\t%18d\t%24s\t%10s\t%12s\n", counter, ptr->numberOfPeople, ptr->totalTested
                    , ptr->totalPositive, races[ptr->raceName], regions[ptr->regionName], towns[ptr->townName]);
        }//end of if statement
        ptr = ptr->next;
    }//end of while loop
    puts("");
}//end of printByRegion function

//prints records with a specified town
void printByTown(Household* ptr){
    if(isEmpty(ptr)){
        puts("This is an empty list");
        return;
    }
    int counter = 0;
    int town ;
    puts("Enter an integer for town: BRAMPTON(0), MISSISSAUGA(1), MAPLE(2), VAUGHAN(3), WHITBY(4) and OSHAWA(5):");
    town = inputValidator(0, 5);
    printf("Records with town: %s\n", towns[town]);
    puts("S.no\tSize\tTotal tested\tTotal tested positive\t\t\tRace\t\tRegion\t\t\tTown");
    while (ptr != NULL ){
        counter++;
        if (town == ptr->townName){
            printf("%d\t%7d\t%10d\t%18d\t%24s\t%10s\t%12s\n", counter, ptr->numberOfPeople, ptr->totalTested
                    , ptr->totalPositive, races[ptr->raceName], regions[ptr->regionName], towns[ptr->townName]);
        }
        ptr = ptr->next;
    }//end of while loop
    puts("");
}//end of printByTown function

//prints records with a specified race
void printByRace(Household* ptr){
    if(isEmpty(ptr)){
        puts("This is an empty list");
        return;
    }
    int counter = 0;
    int race ;
    puts("Enter an integer for race: CAUCASIAN (0), INDIGENOUS(1), AFRICANAMERICAN(2), ASIAN(3), and OTHER(4):");
    race = inputValidator(0, 4);
    printf("Records with race: %s\n", races[race]);
    puts("S.no\tSize\tTotal tested\tTotal tested positive\t\t\tRace\t\tRegion\t\t\tTown");
    while (ptr != NULL ){
        counter++;
        if (race == ptr->raceName){
            printf("%d\t%7d\t%10d\t%18d\t%24s\t%10s\t%12s\n", counter, ptr->numberOfPeople, ptr->totalTested
                    , ptr->totalPositive, races[ptr->raceName], regions[ptr->regionName], towns[ptr->townName]);
        }//end of if statement
        ptr = ptr->next;
    }//end of while loop
    puts("");
}//end of printByRace function

//prints records with a specified minimum number of positive cases in a region
void printByPositive(Household* ptr){
    if(isEmpty(ptr)){
        puts("This is an empty list");
        return;
    }
    int counter = 0;
    int region;
    int lowerbound;
    puts("Enter an integer for region: Peel(0), York(1) and Durham (2):");
    region = inputValidator(0, 2);
    puts("Enter lowerbound of number of Covid-19 positive cases per household in the region:");
    lowerbound = inputValidator(0, 9);
    printf("Records with region: %s and minimum of %d cases\n", regions[region], lowerbound);
    puts("S.no\tSize\tTotal tested\tTotal tested positive\t\t\tRace\t\tRegion\t\t\tTown");
    while (ptr != NULL ){
        counter++;
        if (region == ptr->regionName && ptr->totalPositive >= lowerbound){
            printf("%d\t%7d\t%10d\t%18d\t%24s\t%10s\t%12s\n", counter, ptr->numberOfPeople, ptr->totalTested
                    , ptr->totalPositive, races[ptr->raceName], regions[ptr->regionName], towns[ptr->townName]);
        }
        ptr = ptr->next;
    }//end of while loop
    puts("");
}//end of printByPositive function

//prints ranked records by number of positive household members
void printByPositiveRanking(Household* ptr){
    if(isEmpty(ptr)){
        puts("This is an empty list");
        return;
    }
    int bramptonCounter = 0;
    int mississaugaCounter = 0;
    int mapleCounter = 0;
    int vaughanCounter = 0;
    int whitbyCounter = 0;
    int oshawaCounter = 0;

    while (ptr != NULL ){
        if (!strcmp(towns[ptr->townName],"Brampton")){
            bramptonCounter += ptr->totalPositive;
        }
        else if (!strcmp(towns[ptr->townName],"Mississauga")){
            mississaugaCounter += ptr->totalPositive;
        }
        else if (!strcmp(towns[ptr->townName],"Maple")){
            mapleCounter += ptr->totalPositive;
        }
        else if (!strcmp(towns[ptr->townName],"Vaughan")){
            vaughanCounter += ptr->totalPositive;
        }
        else if (!strcmp(towns[ptr->townName],"Whitby")){
            whitbyCounter += ptr->totalPositive;
        }
        else if (!strcmp(towns[ptr->townName],"Oshawa")){
            oshawaCounter += ptr->totalPositive;
        }//end of if else statement
        ptr = ptr->next;
    }//end of while loop
    int peelCounter = bramptonCounter + mississaugaCounter;
    int yorkCounter = mapleCounter + vaughanCounter;
    int durhamCounter = whitbyCounter + oshawaCounter;
    int regionRank[] = {peelCounter, yorkCounter, durhamCounter};
    char *sortedRegionName[] = {"Peel", "York", "Durham"};
    int j=0, temp = 0;
    char *hold = "";
    //Sort the array in ascending order ---Insertion Sort
    for (int i = 1; i < sizeof(regionRank) / sizeof(regionRank[0]); i++) {
        temp = regionRank[i];
        hold = sortedRegionName[i];
        for (j = i; j > 0; j--) {
            if(regionRank[j - 1] < temp)
                break;
            regionRank[j] = regionRank[j-1];
            sortedRegionName[j] = sortedRegionName[j-1];
        }//end of for loop (inner)
        regionRank[j] = temp;
        sortedRegionName[j] = hold;
    }//end of for loop (outer)
    //Displaying elements in descending order of array after sorting
    puts("Town-wise ranking of regions with highest number of people tested Positive for Covid-19:");
    for (int i = sizeof(regionRank) / sizeof(regionRank[0]) -1 ; i != -1; i--) {
            printf("%s: %d\n", sortedRegionName[i], regionRank[i]);
    }//end of for loop
    puts("\nTown-wise distribution:");
    for (int i = sizeof(regionRank) / sizeof(regionRank[0]) -1 ; i != -1; i--) {
        if (!strcmp(sortedRegionName[i], "Peel")){
            printf("Brampton: %d\nMississauga: %d\n", bramptonCounter, mississaugaCounter);
        } else if (!strcmp(sortedRegionName[i], "York")){
            printf("Maple: %d\nVaughan: %d\n", mapleCounter, vaughanCounter);
        } else if (!strcmp(sortedRegionName[i], "Durham")){
            printf("Whitby: %d\nOshawa: %d\n", whitbyCounter, oshawaCounter);
        }
    }//end of for loop
    puts("");
}//end of printByPositiveRanking function

//adds a household-- to be randomized or user defined
void addHousehold(HouseholdPtr* top, int numberOfPeople, int totalTested, int totalPositive,
                  int regionRand, int townRand, int raceRand){
    HouseholdPtr ptr = malloc(sizeof(Household));
    ptr->numberOfPeople = numberOfPeople;
    ptr->totalTested = totalTested;
    ptr->totalPositive = totalPositive;
    if (raceRand == 0){
        ptr->raceName = 0;
    }
    else if (raceRand == 1){
        ptr->raceName = 1;
    }
    else if (raceRand == 2){
        ptr->raceName = 2;
    }
    else if (raceRand == 3){
        ptr->raceName = Asian;
    }
    else {
        ptr->raceName = Other;
    }
    if (regionRand == 0){
        ptr->regionName = Peel;
        if (townRand == 0){
            ptr->townName = Brampton;
        } else if (townRand == 1){
            ptr->townName = Mississauga;
        } else{
            puts("Invalid input");
        }
    } else if (regionRand == 1){
        ptr->regionName = York;
        if (townRand == 0){
            ptr->townName = Maple;
        } else if (townRand == 1){
            ptr->townName = Vaughan;
        } else{
            puts("Invalid input");
        }
    } else if (regionRand == 2){
        ptr->regionName = Durham;
        if (townRand == 0){
            ptr->townName = Whitby;
        } else if (townRand == 1){
            ptr->townName = Oshawa;
        } else{
            puts("Invalid input");
        }
    }
    ptr->next = *top;
    *top = ptr;
}// end of addHousehold function

//adds a household with random records
HouseholdPtr generateRandHousehold(int maxHouseholdNumber){
    HouseholdPtr ptr = malloc(sizeof(Household));
    int numberOfPeople;
    int totalTested;
    int totalPositive;
    int peopleUnderTwenty;
    int peopleBetweenTwenFif;
    int peopleOverFifty;
    int peopleUnderFiftyChronic;
    int regionRand;
    int townRand;
    int raceRand;
    if (isEmpty(ptr)) {
        puts("memory allocation failure");
        return NULL;
    }
    for (int dex = 0; dex < maxHouseholdNumber; dex++){
        numberOfPeople = generateRand(1,9);
        peopleUnderTwenty = generateRand(0, numberOfPeople);
        peopleOverFifty = generateRand(0, numberOfPeople - peopleUnderTwenty);
        peopleBetweenTwenFif = generateRand(0, (numberOfPeople - peopleUnderTwenty) - peopleOverFifty);
        peopleUnderFiftyChronic = generateRand(0, numberOfPeople - peopleOverFifty);
        peopleBetweenTwenFif = (numberOfPeople - peopleUnderTwenty) - peopleOverFifty;
        totalTested = generateRand(0, numberOfPeople);
        totalPositive = generateRand(0, totalTested);
        regionRand = generateRand(0, 2);
        townRand = generateRand(0, 1);
        raceRand = generateRand(0, 4);
        addHousehold(&ptr, numberOfPeople, totalTested, totalPositive, regionRand, townRand, raceRand);
        if (dex == 0)
            ptr->next = NULL;
    }//end of for loop
    return ptr;
}//end of generateRandHousehold function

//adds a household defined by user
void addCustomHousehold(HouseholdPtr ptr){
    //declaration of integers that holds user input
    int numberOfPeople;
    int totalTested;
    int totalPositive;
    int peopleUnderTwenty;
    int peopleBetweenTwenFif;
    int peopleOverFifty;
    int peopleUnderFiftyChronic;
    int region;
    int town;
    int race;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }//end of while loop
    ptr->next = malloc(sizeof(Household));
    //First & Second prompt:
    puts("Enter region: 0 for Peel, 1 for York, 2 for Durham");
    region = inputValidator(0, 2);
    if (region == 0){
        (ptr->next)->regionName = Peel;
        puts("Enter town: 0 for Brampton, 1 for Mississauga");
        town = inputValidator(0, 1);
        if (town == 0){
            (ptr->next)->townName = Brampton;
        } else if (town == 1){
            (ptr->next)->townName = Mississauga;
        } else{
            puts("Invalid input");
        }
    } else if (region == 1){
        (ptr->next)->regionName = York;
        puts("Enter town: 0 for Maple, 1 for Vaughan");
        town = inputValidator(0, 1);
        if (town == 0){
            (ptr->next)->townName = Maple;
        } else if (town == 1){
            (ptr->next)->townName = Vaughan;
        } else{
            puts("Invalid input");
        }
    } else if (region == 2){
        (ptr->next)->regionName = Durham;
        puts("Enter town: 0 for Whitby, 1 for Oshawa");
        town = inputValidator(0, 1);
        if (town == 0){
            (ptr->next)->townName = Whitby;
        } else if (town == 1){
            (ptr->next)->townName = Oshawa;
        } else{
            puts("Invalid input");
        }
    }
    //Third prompt:
    puts("Enter race\nEnter 0 for Caucasian, 1 for indigenous"
         ", 2 for African_American, 3 for Asian, 4 for Other");
    race = inputValidator(0, 4);
    if (race == 0){
        (ptr->next)->raceName = Caucasian;
    }
    else if (race == 1){
        (ptr->next)->raceName = Indigenous;
    }
    else if (race == 2){
        (ptr->next)->raceName = AfricanAmerican;
    }
    else if (race == 3){
        (ptr->next)->raceName = Asian;
    }
    else {
        (ptr->next)->raceName = Other;
    }//end of else


    puts("Please enter\n"
         "1-total people in the household,\n"
         "2-people under the age of 20,\n"
         "3-people over the age of 50,\n"
         "4-people under 50 with chronic diseases separated by\n"
         "space/tab and make sure all of these are valid integers");
    char buffer[BUFFER_SIZE];
    int ctr = 0;
    int ctr2 = 0;

    //Fourth prompt:
    while (ctr != 4) {
        fgets(buffer, sizeof(buffer), stdin);
        ctr = sscanf(buffer, " %d%d%d%d", &numberOfPeople, &peopleUnderTwenty
                , &peopleOverFifty, &peopleUnderFiftyChronic);
        if (ctr != 4){
            ctr = 0;
            continue;
        }
        if (numberOfPeople < peopleOverFifty + peopleUnderTwenty || numberOfPeople < peopleUnderFiftyChronic){
            puts("Total people in the household can't be less than the sum of "
                 "people under 20 and over 50! Kindly re-enter the data.\n"
                 "Please enter\n"
                 "1-total people in the household,\n"
                 "2-people under the age of 20,\n"
                 "3-people over the age of 50,\n"
                 "4-people under 50 with chronic diseases separated by\n"
                 "space/tab and make sure all of these are valid integers");
            ctr = 0;
            continue;
        } else {
            (ptr->next)->numberOfPeople = numberOfPeople;
            (ptr->next)->peopleUnderTwenty = peopleUnderTwenty;
            (ptr->next)->peopleOverFifty = peopleOverFifty;
            (ptr->next)->peopleBetweenTwenFif = (numberOfPeople - peopleUnderTwenty) - peopleOverFifty;
        }

    }//end of while loop
    //Fifth prompt:
    while (ctr2 != 2) {
        puts("Enter total number of people in the household who were tested for Covid\n"
             "and those who were tested positive separated by space or tab.");
        fgets(buffer, sizeof(buffer), stdin);
        ctr2 = sscanf(buffer, "%d%d", &totalTested, &totalPositive);
        if (totalPositive > totalTested){
            ctr2 = 0;
            puts("Total people tested can't be less than the sum of people positive! Kindly re-enter the data\n");
            continue;
        } else if (totalTested > numberOfPeople || totalPositive > numberOfPeople){
            ctr2 = 0;
            puts("Total people tested/positive can't be more than the household size! Kindly re-enter the data\n");
            continue;
        }// end of if statement
    }//end of while loop
    (ptr->next)->next = NULL;
}//end of addCustomHousehold function

//deletes record(s) by region, town, and race combination
void deleteByKeys(HouseholdPtr* ptr){//needs to be implemented like the addNodeFunction-- HouseholdPtr ptr
    int region;
    int town;
    int race;
    puts("Enter region: 0 for Peel, 1 for York, 2 for Durham");
    region = inputValidator(0, 2);
    if (region == 0){
        region = Peel;
        puts("Enter town: 0 for Brampton, 1 for Mississauga");
        town = inputValidator(0, 1);
        if (town == 0){
            town = Brampton;
        } else if (town == 1){
            town = Mississauga;
        } else{
            puts("Invalid input");
        }
    } else if (region == 1){
        region = York;
        puts("Enter town: 0 for Maple, 1 for Vaughan");
        town = inputValidator(0, 1);
        if (town == 0){
            town = Maple;
        } else if (town == 1){
            town = Vaughan;
        } else{
            puts("Invalid input");
        }
    } else if (region == 2){
        region = Durham;
        puts("Enter town: 0 for Whitby, 1 for Oshawa");
        town = inputValidator(0, 1);
        if (town == 0){
            town = Whitby;
        } else if (town == 1){
            town = Oshawa;
        } else{
            puts("Invalid input");
        }
    }
    puts("Enter race\nEnter 0 for Caucasian, 1 for indigenous"
         ", 2 for African_American, 3 for Asian, 4 for Other");
    race = inputValidator(0, 4);
    if (race == 0){
        race = Caucasian;
    }
    else if (race == 1){
        race = Indigenous;
    }
    else if (race == 2){
        race = AfricanAmerican;
    }
    else if (race == 3){
        race = Asian;
    }
    else {
        race = Other;
    }//end of else
    //Looping through list and checking (and delete) if data matches user input
    HouseholdPtr current, previous;
    previous = NULL;
    current = *ptr;
    int ctr = 0;
    while (current != NULL){
        if(current->regionName == region && current->townName == town && current->raceName == race){
            if(previous == NULL){
                *ptr = current->next;
            } //end of if
            else {
                previous->next = current->next;
            }//end of else
            free(current);
            ctr++;
        }//end of if
        previous = current;
        if (current != NULL){
            current = current->next;
        } //end of if
        else {
            break;
        }//end of else
    }//end of while loop
    printf("%d key(s) found\n", ctr);
}// end of deleteByKeys function

//stores household(linkedlist) records into a file
void storeToFile(Household* ptr){
    if(ptr == NULL){
        puts("This is an empty list");
        return;
    }
    FILE *cfPtr; /* cfPtr = clients.dat file pointer */
    char filePath[20] = "..//data//";
    char fileName[20];
    int run = 0;
    while (run == 0){
        puts("Enter file name with extension, for example clients.txt");
        scanf("%s", fileName);
        char *file = strcat(filePath, fileName);
        //check if file is found
        int ctr = 0;
        if ( ( cfPtr = fopen( file, "w" ) ) == NULL ) {
            printf( "File could not be opened\n" );
            run = 0;
            continue;
        }//end of if
        else {
            //loop through the list and write each line to file
            while (ptr != NULL){
                fprintf(cfPtr, "%d %d %d %s %s %s\n", ptr->numberOfPeople, ptr->totalTested
                        , ptr->totalPositive, races[ptr->raceName], regions[ptr->regionName], towns[ptr->townName]);
                ptr = ptr->next;
                ctr++;
            }//end of while loop
            //close file
            fclose( cfPtr );
            printf("%d records written successfully as a text file: %s\n", ctr, file);
            run = 1;
        } //end of else

    }

}//end of storeToFile function

//displays records from file save by the user
void displayFile(Household* ptr){
    FILE *cfPtr; //<-- pointer to our file: records.txt
    int counter = 0;
    int numberOfPeople;
    int totalTested;
    int totalPositive;
    char regionName[30];
    char townName[30];
    char raceName[30];
    char filePath[20] = "..//data//";
    char fileName[20];

    int run = 0;
    while (run == 0){
        puts("Enter file name with extension, for example clients.txt");
        scanf("%s", fileName);
        char *file = strcat(filePath, fileName);
        //check if file is found
        if ( ( cfPtr = fopen( file, "r" ) ) == NULL ) {
            printf( "File could not be opened. Try again.\n" );
            run = 0;

        } //end of if
            //read file contents
        else {
            puts("S.no\tSize\tTotal tested\tTotal tested positive\t\t\tRace\t\tRegion\t\t\tTown");
            fscanf( cfPtr, "%d%d%d%s%s%s", &numberOfPeople, &totalTested
                    , &totalPositive, raceName, regionName, townName);
            //loop through file
            while (!feof(cfPtr)) {
                counter++;
                printf( "%d\t%7d\t%10d\t%18d\t%24s\t%10s\t%12s\n", counter, numberOfPeople, totalTested
                        , totalPositive, raceName, regionName, townName );
                fscanf( cfPtr, "%d%d%d%s%s%s", &numberOfPeople, &totalTested
                        , &totalPositive, raceName, regionName, townName);

            }//end of while loop
            //close the file
            fclose( cfPtr );
            run = 1;
        } //end of else
    }

}//end of displayFile function