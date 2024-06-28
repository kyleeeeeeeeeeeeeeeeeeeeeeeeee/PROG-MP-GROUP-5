#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CINEMAS 10
#define MAX_SHOWINGS 6
#define MAX_SEATS 50

typedef char longstr[101];
typedef char str[31];

struct MovieTag{
   int numCinema; // not yet implemented
   str title;
   longstr description;
   str runTime;
};

struct showTag{
    str showingTime;
    str seats[5][10];
}
struct ViewMovieTag{    // main tag: structure for showing movies (1 showing time = 1 cinema)
    struct MovieTag Movie;
    struct showTag show[15];
};

struct ViewMovieTag cinemas[MAX_CINEMAS]; // Array of cinema schedules

void loadSched(char *filename)
{
   int i, j, k, cinemaIndex = 0;
   FILE *fp; 
   fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Unable to open file: %s\n", filename);
        return;
    }
    while (fscanf(fp, "%d\n", &cinemaIndex) != EOF) 
    {
        if (cinemaIndex >= MAX_CINEMAS) 
        {
            printf("Cinema index %d out of bounds\n", cinemaIndex);
            fclose(fp);
            return;
        }

    while (!feof(fp)) 
    {                
        if (fscanf(fp, "%d\n", &cinemaIndex) == 1) 
        {
            if (cinemaIndex < MAX_CINEMAS) 
            {    
                // Read movie title, description, and runtime from file
                fscanf(fp, "%30[^\n]\n", cinemas[cinemaIndex].Movie.title);
                fscanf(fp, "%100[^\n]\n", cinemas[cinemaIndex].Movie.description);
                fscanf(fp, "%30[^\n]\n", cinemas[cinemaIndex].Movie.runTime);

                // Read showing times and initialize seat availability
                for (i = 0; i < MAX_SHOWINGS; i++) 
                {
                    if (fscanf(fp, "%30[^\n]\n", cinemas[cinemaIndex].show[i].showingTime) == 1) 
                    {
                        // Initialize seats to 'O' indicating available
                        for (j = 0; j < 5; j++) 
                        {
                            for (k = 0; k < 10; k++) 
                            {
                                strcpy(cinemas[cinemaIndex].show[i].seats[j][k], "O");
                            }
                        }
                    }
                }
            } 
            else 
            {
                printf("Cinema index %d out of bounds\n", cinemaIndex);
                fclose(fp);
                return;
            }
        }
    }
   fclose(fp);
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


