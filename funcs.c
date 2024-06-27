#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CINEMAS 10
#define MAX_SHOWINGS 6
#define MAX_SEATS 50

typedef struct {
    char title[100];
    char description[256];
    int running_time; 
    char show_times[MAX_SHOWINGS][10]; 
    char seats[MAX_SHOWINGS][MAX_SEATS]; 
} Movie;

typedef Movie Cinema[MAX_CINEMAS];

void loadSched(char *filename)
{
  
}

void saveExit(char *filename)
{
  
}

void viewSched()
{
  
}

void displaySeat(int cinemaNum, char *showTime)
{
  
}

void selectSeat(int cinemaNum, char *showTime)
{
  
}

void searchTitle(char *title)
{
  
}

void searchTime(char *time)
{

}

void printTicket(int cinema_number, char *title, char *showTime, char *seatNum)
{

}

int checkAvailability(int cinemaNum, char *showTime, char *seatNum)
{

}

void markTaken(int cinemaNum, char *showTime, char *seatNum)
{

}

void mainMenu()
{

}


