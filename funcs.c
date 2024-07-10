#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CINEMAS 10
#define MAX_SHOWINGS 6
#define MAX_SEATS 50

typedef char longstr[101];
typedef char str[31];

struct MovieTag{
   int numCinema;
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


void initializeTable(int index, int index2)
{
    //initialize of seats
    int i, j;
    for (i=0; i<5; i++){
        for (j=0; j<10; j++)
        {
            switch (i) 
            {
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

            switch (j) 
            {
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

void displayTable(int index, int index2)
{
    int i, j;
    for (i=0; i<5; i++)
    {
        for (j=0; j<10; j++)
        {
            printf("%s ", cinemas[index].show[index2].seats[i][j]);
        }
        printf("\n\n");
    }
}

void printTicket(int title, int time, int numSeats, int row, int col, int ticket){
    int i, j;
    FILE *fp;
    str filename;
    char ticketNumber = '0';

    strcpy(filename, "");   // clear filename
    strcpy(filename, "Ticket"); 
    ticketNumber = '0' + ticket;
    filename[6] = ticketNumber; //number of filename
    strcat(filename, ".txt");   //file extension (text file)

    fp = fopen(filename, "w");
    if (strcmp(cinemas[title].show[time].seats[row][col], "X") == 0){
        fprintf(fp, "%d\n", cinemas[title].Movie.numCinema+1);
        fprintf(fp, "%s\n", cinemas[title].Movie.title);
        fprintf(fp, "%s\n", cinemas[title].show[time].showingTime);
        fprintf(fp, "%c%d\n", row+65, col+1);
    }
    fprintf(fp, "\n");
    fclose(fp);
}

void seatSelect(){
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

    int row, col; //index of seats

    while (titleValid != 1){
        printf("Enter Movie Title: ");
        scanf(" %[^\n]s", title);
        for (i=0;i<6;i++){
            if (strcmp(title, cinemas[i].Movie.title) == 0){
                titleValid = 1;
                titleIndex = i;
            }
        }
    }

    printf("Movie Title: %s\n", cinemas[titleIndex].Movie.title);
    printf("Showing Times:\n");
    for (j=0;j<3;j++){
        printf("\n%s", cinemas[titleIndex].show[j].showingTime);
    }
    printf("\n");

    do{
        printf("Enter Showing Time: ");
        scanf(" %[^\n]s", showtime);
        for (i=0;i<3;i++){
            if (strcmp(cinemas[titleIndex].show[i].showingTime, showtime) == 0){
                if (cinemas[titleIndex].show[i].seatsTaken == 50){
                    printf("Sorry, all seats are taken.\n");
                }
                else if (cinemas[titleIndex].show[i].seatsTaken < 50){
                    timeValid = 1;
                    timeIndex=i;
                }
            }
        }
    } while (timeValid != 1);

    displayTable(titleIndex, timeIndex);

    do{
        printf("\nEnter Number of Seats: ");
        scanf("%d", &numSeats);
        
    } while (!(numSeats > 0 && numSeats < 4)); // can reserve up to 3 seats only

    do {
        printf("\nEnter Seat[%d]: ", k+1);
        scanf("%s", seats[k]);

        for (i=0;i<5; i++){
            for (j=0;j<10; j++){
                if (strcmp(cinemas[titleIndex].show[timeIndex].seats[i][j], seats[k]) == 0){
                    strcpy(cinemas[titleIndex].show[timeIndex].seats[i][j], "X");
                    isValid=1;
                    validSeats++;
                    row = i;
                    col = j;
                    k++;
                    cinemas[titleIndex].show[timeIndex].seatsTaken++;
                }
            }
        }
        if (isValid == 1){
            isValid = 0;
            //printing of tickets
            printTicket(titleIndex, timeIndex, numSeats, row, col, k);
        }
        else if (isValid == 0){
            printf("\nSeat Taken! Please choose again");
        }

    } while (!(k==numSeats));

    displayTable(titleIndex, timeIndex);
}


void preloadSched(char *filename)
{
   int i, cinemaIndex = 0;
   FILE *fp; 
   fp = fopen(filename, "r"); // Open file for reading
    if (fp == NULL) 
    {
        printf("Unable to open file: %s\n", filename);
        return;
    }
   // Read cinema index and schedule details 
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
                        // Initialize seats
                        initializeTable(cinemaIndex, i);
                    }
                }
    }
   fclose(fp);
}

void saveExit(char *filename)
{  
   int i, j, k, l;
   FILE *fp = fopen(filename, "w"); // Open file for writing
    if (fp == NULL) 
    {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }
   
   // Iterate through each cinema
   for (i = 0; i < MAX_CINEMAS; i++) 
    {
        if (strlen(cinemas[i].Movie.title) > 0) // Check if cinema has a valid movie title
        {
            fprintf(fp, "Cinema No: %d\n", cinemas[i].Movie.numCinema);
            fprintf(fp, "Title: %s\n", cinemas[i].Movie.title);
           
            // Iterate through each showing time
            for (j = 0; j < MAX_SHOWINGS; j++) 
            {
                if (strlen(cinemas[i].show[j].showingTime) > 0) // Check if showing time is valid
                {
                    fprintf(fp, "Time: %s\n", cinemas[i].show[j].showingTime);
                    fprintf(fp, "Taken Seats:\n");

                  // Iterate through each seat 
                  for (k = 0; k < 5; k++) 
                    {
                        for (l = 0; l < 10; l++) 
                        {   
                           // "X" label if seat is taken
                           if (strcmp(cinemas[i].show[j].seats[k][l], "X") == 0) 
                            { 
                              // Seat identifier ex: A1, B2 
                              fprintf(fp, "%c%d, ", 'A' + k, l + 1);
                            }
                        }
                    }
                    fprintf(fp, "\n\n"); // for formatting purposes
                }
            }
        }
    }
    fclose(fp);
}

void viewSched()
{
   int i, j;  
   
   // Iterate through each cinema
   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      // check if cinema has a valid movie title
      if (strlen(cinemas[i].Movie.title) > 0) 
      {
         printf("Cinema %d: %s\n", cinemas[i].Movie.numCinema, cinemas[i].Movie.title);
         
         // Iterate through each showing time
         for (j = 0; j < MAX_SHOWINGS; j++) 
         {
            // check if showing time is valid
            if (strlen(cinemas[i].show[j].showingTime) > 0) 
            {
                  printf("  Show Time: %s\n", cinemas[i].show[j].showingTime);
            }
         }
      }
    }
}


void searchTitle(char *title)
{
   int i, j;

   // Iterate through each cinema
   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      // check if cinema has valid movie title & matches the search title
      if (strlen(cinemas[i].Movie.title) > 0 && strcmp(cinemas[i].Movie.title, title) == 0) 
      {
            printf("Cinema %d: %s\n", cinemas[i].Movie.numCinema, cinemas[i].Movie.title);
         
           // Iterate through each showing time
            for (j = 0; j < MAX_SHOWINGS; j++) 
            {
               // check if showing time is valid
               if (strlen(cinemas[i].show[j].showingTime) > 0) 
               {
                  printf("  Show Time: %s\n", cinemas[i].show[j].showingTime);
                  printf("  Available Seats: %d\n", MAX_SEATS - cinemas[i].show[j].seatsTaken);
               }
            }
        }
    }
}

void searchTime(char *time)
{
   int i, j;
   
   // Iterate through each cinema
   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      // Iterate through each showing time  
      for (j = 0; j < MAX_SHOWINGS; j++) 
        {
            // check if showing time is valid & matches the search time
            if (strlen(cinemas[i].show[j].showingTime) > 0 && strcmp(cinemas[i].show[j].showingTime, time) == 0) 
            {
                printf("Cinema %d: %s\n", cinemas[i].Movie.numCinema, cinemas[i].Movie.title);
                printf("  Show Time: %s\n", cinemas[i].show[j].showingTime);
                printf("  Available Seats: %d\n", MAX_SEATS - cinemas[i].show[j].seatsTaken);
            }
        }
    }
}

void mainMenu()
{
    int choice, cinemaNum, titleIndex = 0, timeIndex = 0;
    char title[31], time[31], seatNum[5];
    do{
      // Display menu options       
      printf("\n===== Main Menu =====\n");
      printf("1. Preload Schedule\n");
      printf("2. View Schedule\n");
      printf("3. Select Seats\n");
      printf("4. Search Movie\n");
      printf("5. Print Ticket\n");
      printf("6. Save and Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      getchar(); // Consume newline left by scanf
        
        switch (choice) 
        {
            case 1:
               preloadSched("movieSched.txt"); // preload current schedule
               printf("Schedule loaded successfully!\n");
               break;
            case 2:
               viewSched(); // view available schedule
               break;
            case 3:
               seatSelect(); // select seats
               break;
            case 4:
               printf("Enter Movie Title: ");
               scanf(" %[^\n]s", title);
               searchTitle(title); // search movie by title
               printf("Enter Show Time: ");
               scanf(" %[^\n]s", time);
               searchTime(time); // search movie by time
               break;
            case 5:
               printf("Enter Cinema Number: ");
               scanf("%d", &cinemaNum);
               printf("Enter Movie Title: ");
               scanf(" %[^\n]s", title);
               printf("Enter Show Time: ");
               scanf(" %[^\n]s", time);
               printf("Enter Seat Number (ex: A1, B2): ");
               scanf(" %[^\n]s", seatNum);
               printTicket("Ticket.txt", titleIndex, timeIndex); // print ticket
               break;
            case 6:
               saveExit("movieSched.txt"); 
               printf("Schedule saved successfully! Exiting program.\n");
               break;
            default:
               printf("Invalid choice! Please enter a valid number.\n");
               break;
        }
    } while (choice != 6); // Continue until the user chooses to exit
}


