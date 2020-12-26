/* Covid Analytics
 * Created by: Christian Tapnio 2020-11-05
 * C program to store, analyze and update Covid-19 information about Greater Toronto Area
 * (GTA) for the health ministry of Ontario
 * Tester file
 * */
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    //default random generated records
    HouseholdPtr household = generateRandHousehold(100);
    printAll(household);

    int option = 1;
    while(option != 0){
        //show menu
        puts("Menu:\n"
             "Enter your choice to\n"
             "1. display households of a region\n"
             "2. display households of a town\n"
             "3. display households of a race\n"
             "4. display households of a region with a given minimum number of people tested positive for Covid-19\n"
             "5. display the regions town-wise ranking of number of people tested positive for Covid-19\n"
             "6. add a record\n"
             "7. delete all records of a region, town and race triplet\n"
             "8. display updated data\n"
             "9. store data to a file\n"
             "10. display data from file\n"
             "0. to exit the program");
        //case switch based on user option(input)
        scanf("%d", &option);
        switch (option){
            case 0 : {
                puts("Thank you");
                exit(0);
            }
            case 1 : {
                printByRegion(household);
                continue;
            }
            case 2 : {
                printByTown(household);
                continue;
            }
            case 3 : {
                printByRace(household);
                continue;
            }
            case 4 : {
                printByPositive(household);
                continue;
            }
            case 5 : {
                printByPositiveRanking(household);
                continue;
            }
            case 6 : {
                addCustomHousehold(household);
                continue;
            }
            case 7 : {
                deleteByKeys(&household);
                continue;
            }
            case 8 : {
                printAll(household);
                continue;
            }
            case 9 : {
                storeToFile(household);
                continue;
            }
            case 10 : {
                displayFile(household);
                continue;
            }
            default : {
                puts("Invalid Input");
                continue;
            }
        }
    }
    return 0;
}
