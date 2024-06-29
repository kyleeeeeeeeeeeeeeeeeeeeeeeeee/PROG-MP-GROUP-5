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
   int seatsTaken;
};
struct ViewMovieTag{    // main tag: structure for showing movies (1 showing time = 1 cinema)
    struct MovieTag Movie;
    struct showTag show[15];
};

struct ViewMovieTag cinemas[MAX_CINEMAS]; // Array of cinema schedules


void initializeTable(int index, int index2){
    //initialize of seats
    int i, j, k=0;
    for (i=0; i<5; i++){
        for (j=0; j<10; j++){
            switch (i) {
            case 0:
                strcpy(cinemas[index].show[index2].seats[i][j], "A");
                break;
            case 1:
                strcpy(cinemas[index].show[index2].seats[i][j], "B");
                break;
            case 2:
                strcpy(cinemas[index].show[index2].seats[i][j], "C");
                break;
            case 3:
                strcpy(cinemas[index].show[index2].seats[i][j], "D");
                break;
            case 4:
                strcpy(cinemas[index].show[index2].seats[i][j], "E");
                break;
            }

            switch (j) {
            case 0:
                strcat(cinemas[index].show[index2].seats[i][j], "1");
                break;
            case 1:
                strcat(cinemas[index].show[index2].seats[i][j], "2");
                break;
            case 2:
                strcat(cinemas[index].show[index2].seats[i][j], "3");
                break;
            case 3:
                strcat(cinemas[index].show[index2].seats[i][j], "4");
                break;
            case 4:
                strcat(cinemas[index].show[index2].seats[i][j], "5");
                break;
            case 5:
                strcat(cinemas[index].show[index2].seats[i][j], "6");
                break;
            case 6:
                strcat(cinemas[index].show[index2].seats[i][j], "7");
                break;
            case 7:
                strcat(cinemas[index].show[index2].seats[i][j], "8");
                break;
            case 8:
                strcat(cinemas[index].show[index2].seats[i][j], "9");
                break;
            case 9:
                strcat(cinemas[index].show[index2].seats[i][j], "10");
                break;
            }
        }
    }
}


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
    while (fscanf(fp, "%d\n", &cinemaIndex) == 1) 
    {
        if (cinemaIndex >= MAX_CINEMAS) 
        {
            printf("Cinema index %d out of bounds\n", cinemaIndex);
            fclose(fp);
            return;
        }    
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
void displayTable(struct ViewMovieTag *view, int index, int index2){
    int i, j, k=0;
    for (i=0; i<5; i++){
        for (j=0; j<10; j++){
            printf("%s ", view[index].show[index2].seats[i][j]);
        }
        printf("\n\n");
    }
}

void seatSelect(struct ViewMovieTag Main[]){
    int i, j, k=0;
    str title;
    str showtime;
    int numSeats;
    str seats[3];
    int titleValid =0;
    int titleIndex;
    int timeValid=0;
    int timeIndex;
    int validSeats=0;
    int isValid=0;

    do{
        printf("Enter Movie Title: ");
        scanf("%[^\n]%*c", title);
        for (i=0;i<6;i++){
            if (strcmp(title, Main[i].Movie.title) == 0){
                titleValid = 1;
                titleIndex = i;
            }
        }
    } while (titleValid != 1);

    printf("Movie Title: %s\n", Main[titleIndex].Movie.title);
    printf("Showing Times:\n");
    for (j=0;j<3;j++){
        printf("\n%s", Main[titleIndex].show[j].showingTime);
    }
    printf("\n");

    do{
        printf("Enter Showing Time: ");
        scanf("%[^\n]%*c", showtime);
        for (i=0;i<3;i++){
            if (strcmp(Main[titleIndex].show[i].showingTime, showtime) == 0){
                if (Main[titleIndex].show[i].seatsTaken == 50){
                    printf("Sorry, all seats are taken.\n");
                }
                else if (Main[titleIndex].show[i].seatsTaken < 50){
                    timeValid = 1;
                    timeIndex=i;
                }
            }
        }
    } while (timeValid != 1);

    displayTable(Main, titleIndex, timeIndex);

    do{
        printf("\nEnter Number of Seats: ");
        scanf("%d", &numSeats);
        
    } while (!(numSeats > 0 && numSeats < 4));

    do {
        printf("\nEnter Seat[%d]: ", k+1);
        scanf("%s", seats[k]);

        for (i=0;i<5; i++){
            for (j=0;j<10; j++){
                if (strcmp(Main[titleIndex].show[timeIndex].seats[i][j], seats[k]) == 0){
                    strcpy(Main[titleIndex].show[timeIndex].seats[i][j], "X");
                    isValid=1;
                    validSeats++;
                    k++;
                    Main[titleIndex].show[timeIndex].seatsTaken++;
                }
            }
        }
        if (isValid == 1){
            isValid = 0;
        }
        else if (isValid == 0){
            printf("\nSeat Taken! Please choose again");
        }

    } while (!(k==numSeats));

    displayTable(Main, titleIndex, timeIndex);

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


