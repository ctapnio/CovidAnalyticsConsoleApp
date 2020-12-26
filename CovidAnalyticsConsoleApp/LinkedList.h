/* Covid Analytics
 * Created by: Christian Tapnio 2020-11-05
 * C program to store, analyze and update Covid-19 information about Greater Toronto Area
 * (GTA) for the health ministry of Ontario
 * Header file
 * */

#ifndef CHRISTIANTAPNIOASSIGN3_LINKEDLIST_H
#define CHRISTIANTAPNIOASSIGN3_LINKEDLIST_H
#define BUFFER_SIZE 100
#define ROGUE_VAL INT_MIN


//Enums used for LinkedList data
enum region{
    Peel = 0, York = 1, Durham = 2
};
enum town{
    Brampton = 0, Mississauga = 1, Maple = 2, Vaughan = 3, Whitby = 4, Oshawa = 5
};
enum race{
    Caucasian = 0, Indigenous = 1, AfricanAmerican = 2, Asian = 3, Other = 4
};

//LinkedList for our household records
typedef struct def{
    int numberOfPeople;
    int totalTested;
    int totalPositive;
    int peopleUnderTwenty;
    int peopleOverFifty;
    int peopleBetweenTwenFif;
    int peopleUnderFiftyChronic;
    enum region regionName;
    enum town townName;
    enum race raceName;
    struct def* next;
}Household, *HouseholdPtr;

//Prototypes
int generateRand(int min, int max);
int inputValidator(int min, int max);

void printAll(Household* ptr);
void printByRegion(Household* ptr);
void printByTown(Household* ptr);
void printByRace(Household* ptr);
void printByPositive(Household* ptr);
void printByPositiveRanking(Household* ptr);

void addHousehold(HouseholdPtr* top, int numberOfPeople, int totalTested, int totalPositive, int regionRand, int townRand, int raceRand);
HouseholdPtr generateRandHousehold(int maxHouseholdNumber);
void addCustomHousehold(HouseholdPtr ptr);
void deleteByKeys(HouseholdPtr* ptr);

void storeToFile(Household* ptr);
void displayFile(Household* ptr);
#endif //CHRISTIANTAPNIOASSIGN3_LINKEDLIST_H
