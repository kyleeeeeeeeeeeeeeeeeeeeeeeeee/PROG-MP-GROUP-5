#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CINEMAS 10
#define MAX_SHOWINGS 6
#define MAX_SEATS 50
typedef char longstr[101];
typedef char str[31];

struct InputTag{
    str title;
    str time
    str numSeats;
    str seats[5][10];
};

struct MovieTag{
   int numCinema;
   str title;
   longstr description;
   str runTime;
};

struct ViewMovieTag{
    struct MovieTag Movie;
    str showingTime;
};

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

void printTicket(int cinemaNum, char *title, char *showTime, char *seatNum)
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
 int choice, cinemaNum;
 char filename, showTime, title, time, seatNum;
    do{
        printf("1. Load Schedule\n");
        printf("2. View Schedule\n");
        printf("3. Select Seats\n");
        printf("4. Search Movie\n");
        printf("5. Print Ticket\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // loadSched(&filename);
                break;
            case 2:
                viewSched();
                break;
            case 3:
                selectSeat(cinemaNum, &showTime);
                break;
            case 4:
               searchTitle(&title);
               searchTime(&time);
               break;
            case 5:
                printTicket(cinemaNum, &title, &showTime, &seatNum);
                break;
            case 6:   
                // Exit
        } while(choice != 6);
}


