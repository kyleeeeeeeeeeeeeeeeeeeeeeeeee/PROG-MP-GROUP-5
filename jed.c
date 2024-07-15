/*********************************************************************************************************
This is to certify that this project is our own work, based on our personal efforts in studying and applying 
the concepts learned. We have constructed the functions and their respective algorithms and corresponding 
code by ourselves. The program was run, tested, and debugged by our own efforts. We further certify that we 
have not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
Jediaelle Denise De Castro, DLSU ID# 12308226
Kyle Gabriel A. Maristela, DLSU ID# 12307777
*********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CINEMAS 6
#define MAX_SHOWINGS 6
#define MAX_SEATS 50

typedef char longString[101];
typedef char string[31];

struct sMovieTag
{
   int nNumCinema;
   string strTitle;
   longString strDescription;
   string strRunTime;
};

struct sShowTag
{
    string strShowTime;
    string arrSeats[5][10];
    int nTakenSeats;
};

struct sViewMovieTag // main tag: structure for showing movies (1 showing time = 1 cinema)
{    
    struct sMovieTag sMovie;
    struct sShowTag arrShow[MAX_SHOWINGS];
};

struct sViewMovieTag arrCinemas[MAX_CINEMAS]; // Array of cinema schedules

/* initializeTable initializes the seat labels for a cinema's show.
@param nIndex - index of the cinema
@param nIndex2 - index of the show
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
initializeTable(int nIndex, 
                int nIndex2)
{
   int nRow, nCol;
   
   for (nRow = 0; nRow < 5; nRow++)
   {
      for (nCol = 0; nCol < 10; nCol++)
      {
         switch (i) 
         {
            case 0:
                strcpy(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "A");
                break;
            case 1:
                strcpy(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "B");
                break;
            case 2:
                strcpy(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "C");
                break;
            case 3:
                strcpy(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "D");
                break;
            case 4:
                strcpy(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "E");
                break;
            } 
         
         switch (j) 
         {
            case 0:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "1");
               break;
            case 1:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "2");
               break;
            case 2:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "3");
               break;
            case 3:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "4");
               break;
            case 4:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "5");
               break;
            case 5:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "6");
               break;
            case 6:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "7");
               break;
            case 7:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "8");
               break;
            case 8:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "9");
               break;
            case 9:
               strcat(arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol], "10");
               break;
         }
      }
   }    
}

/* displayTable prints the seating arrangement for a specific cinema show.
@param nIndex - index of the cinema
@param nIndex2 - index of the show
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
displayTable(int nIndex, 
             int nIndex2)
{
   int nRow, nCol;
   
   for (nRow = 0; nRow < 5; nRow++)
   {
      for (nCol = 0; nCol < 10; nCol++)
      {
         printf("%s ", arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol]);
      }
      printf("\n\n");
   }
}

/* preLoadSched reads and preloads schedule data from a file into the cinema system 
   at the start of the program.
@param *pFilename - name of the file containing the schedule data
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields0.
*/
void 
preLoadSched(char *pFilename)
{
   int i, j = 0, nCinemaIndex;
   string strLine;
   
   FILE *pFp; 
   pFp = fopen(pFilename, "r");
   
   if (pFp == NULL) 
   {
      printf("Unable to open file: %s\n", pFilename);
   }   
   else
   {
      printf("Data has been successfully imported\n");
      fscanf(fp, "%[^\n]\n", strLine);
      
      for (j = 0; j < 6; j++)
      {
         if (strlen(strLine) == 1)
         {
            nCinemaIndex = strLine[0] - 48; 
            if (nCinemaIndex > MAX_CINEMAS) 
            {
                    printf("Cinema index %d out of bounds\n", nCinemaIndex);
                    fclose(pFp);
            }
            else if (nCinemaIndex > 0 && nCinemaIndex < 7)
            {
                    arrCinemas[nCinemaIndex-1].sMovie.nNumCinema = nCinemaIndex;
                    // Read movie title, description, and runtime from file
                    fscanf(fp, "%[^\n]\n", arrCinemas[nCinemaIndex-1].sMovie.strTitle);
                    fscanf(fp, "%[^\n]\n", arrCinemas[nCinemaIndex-1].sMovie.strDescription);
                    fscanf(fp, "%[^\n]\n", arrCinemas[nCinemaIndex-1].sMovie.strRunTime);
               
               for (i = 0; i < MAX_SHOWINGS + 1; i++) 
               {
                  fscanf(pFp, "%30[^\n]\n", strLine);
                  if (strlen(strLine) > 1)
                  {
                     strcpy(arrCinemas[nCinemaIndex - 1].arrShow[i].strShowTime, strLine);
                     initializeTable(nCinemaIndex - 1, i);
                  }
                  else 
                  {
                     i += MAX_SHOWINGS;
                  }
               }
            }
         }  
      }
   }
   fclose(pFp);
}

/* loadSched reads and loads schedule data from a file into the cinema system,
   prompting the user for a filename that will be used.
@param none - This function does not have a parameter
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
loadSched()
{
   int i, j = 0, nCinemaIndex;
   string strLine, pFilename;
   FILE *pFp; 
   
   printf("Enter filename: ");
   scanf("%s", pFilename);
   pFp = fopen(pFilename, "r");

   while (pFp == NULL) 
   {
      printf("Unable to open file. Please input filename again:\n");
      scanf("%s", pFilename);
      pFp = fopen(pFilename, "r");     
   }
   if (pFp != NULL)
   {
      printf("Data has been successfully imported\n");
      fscanf(pFp, "%[^\n]\n", strLine);
      
      for (j = 0; j < 6; j++)
      {
         if (strlen(line) == 1)
         {
            nCinemaIndex = strLine[0] - 48;
            if (nCinemaIndex > MAX_CINEMAS) 
            {
               printf("Cinema index %d out of bounds\n", nCinemaIndex);
               fclose(pFp);
            }  
            else if (nCinemaIndex > 0 && nCinemaIndex < 7)
            {
               arrCinemas[nCinemaIndex - 1].sMovie.nNumCinema = nCinemaIndex;
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strTitle);
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strDescription);
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strRunTime);
               
               for (i = 0; i < MAX_SHOWINGS+1; i++) 
               {
                  fscanf(pFp, "%30[^\n]\n", strLine);
                  if (strlen(strLine) > 1) 
                  {
                     strcpy(arrCinemas[nCinemaIndex-1].arrShow[i].strShowTime, strLine);
                     initializeTable(nCinemaIndex-1, i);
                  }
                  else 
                  {
                                i += MAX_SHOWINGS;
                  }
               }
            }
         }  
      }
   }
   fclose(pFp);
}

/* viewSched displays the schedule of movies and their show times for each cinema.
@param none - This function does not have a parameter
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
viewSched()
{
   int i, j;  
   
   // Iterate through each cinema
   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      if (strlen(arrCinemas[i].sMovie.strTitle) > 0) 
      {
         printf("Cinema %d: %s\n", arrCinemas[i].sMovie.nNumCinema, arrCinemas[i].sMovie.strTitle);
         for (j = 0; j < MAX_SHOWINGS; j++) 
         {
            if (strlen(arrCinemas[i].sShow[j].strShowTime) > 0) 
            {
               printf("Show Time: %s\n", cinemas[i].sShow[j].strShowTime);
            }
         }
      }
      printf("\n");
    }
}

/* printTicket creates and prints a ticket to a text file.
@param title - index of the movie title in cinemas array
@param time - index of the show time in cinemas array
@param numSeats - number of seats in the cinema
@param row - row number of the seat
@param col - column number of the seat
@param ticket - ticket number
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
printTicket(int title, 
            int time, 
            int numSeats, 
            int row, 
            int col, 
            int ticket)
{
   str filename;
   char ticketNumber = '0';
   FILE *fp;

   strcpy(filename, "");   // clear filename
   strcpy(filename, "Ticket"); 
   
   ticketNumber = '0' + ticket;
   filename[6] = ticketNumber; //number of filename
   
   strcat(filename, ".txt");   //file extension (text file)
   fp = fopen(filename, "w");
   
   if (strcmp(cinemas[title].show[time].seats[row][col], "X") == 0)
   {
      fprintf(fp, "%d\n", cinemas[title].Movie.numCinema+1);
      fprintf(fp, "%s\n", cinemas[title].Movie.title);
      fprintf(fp, "%s\n", cinemas[title].show[time].showingTime);
      fprintf(fp, "%c%d\n", row + 65, col + 1);
    }
   fprintf(fp, "\n");
   fclose(fp);
}

/* selectSeat prompts the user to select a movie, showing time, and seats, 
then reserves the selected seats.
@param none - This function does not have a parameter
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
selectSeat()
{
   int i, j, k = 0, numSeats, titleValid = 0, titleIndex = 0, timeValid = 0;
   int timeIndex, validSeats = 0, isValid = 0, row, col;
   str title, showtime, seats[3];

   while (titleValid != 1)
   {
      printf("Enter Movie Title: ");
      scanf(" %[^\n]s", title);
      
      for (i = 0; i < 6; i++)
      {
         if (strcmp(title, cinemas[i].Movie.title) == 0)
         {
            titleValid = 1;
            titleIndex = i;
         }
      }
   }
   
   printf("Movie Title: %s\n", cinemas[titleIndex].Movie.title);
   printf("Showing Times:\n");
   
   for (j = 0; j < 6; j++)
   {
      printf("\n%s", cinemas[titleIndex].show[j].showingTime);
   }
   
   printf("\n");
   
   do
   {
      printf("Enter Showing Time: ");
      scanf(" %[^\n]s", showtime);
      
      for (i = 0; i < 6; i++)
      {
         if (strcmp(cinemas[titleIndex].show[i].showingTime, showtime) == 0)
         {
            if (cinemas[titleIndex].show[i].seatsTaken == 50)
            {
               printf("Sorry, all seats are taken.\n");
            }
            else if (cinemas[titleIndex].show[i].seatsTaken < 50)
            {
               timeValid = 1;
               timeIndex = i;
            }
         }
      }
   } while (timeValid != 1);
   
   displayTable(titleIndex, timeIndex);

   do
   {
      printf("\nEnter Number of Seats: ");
      scanf("%d", &numSeats); 
   } while (!(numSeats > 0 && numSeats < 4)); // can reserve up to 3 seats only
   
   do 
   {
      printf("\nEnter Seat[%d]: ", k + 1);
      scanf("%s", seats[k]);

      for (i = 0; i < 5; i++)
      {
         for (j = 0; j < 10; j++)
         {
            if (strcmp(cinemas[titleIndex].show[timeIndex].seats[i][j], seats[k]) == 0)
            {
               strcpy(cinemas[titleIndex].show[timeIndex].seats[i][j], "X");
               isValid = 1;
               validSeats++;
               row = i;
               col = j;
               k++;
               cinemas[titleIndex].show[timeIndex].seatsTaken++;
               i = i + 5;
               j = j + 10;
            }
         }
      }
      if (isValid == 1)
      { 
         isValid = 0;
         printTicket(titleIndex, timeIndex, numSeats, row, col, k); 
      }
      else if (isValid == 0)
      {
         printf("\nSeat Taken! Please choose again");
      }
    } while (!(k == numSeats));

    displayTable(titleIndex, timeIndex);
}

/* searchTitle searches for a movie title across all cinemas and displays its details.
@param title - pointer to a string containing the movie title to search for
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
searchTitle(char *title)
{
   int i, j;

   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      if (strlen(cinemas[i].Movie.title) > 0 && strcmp(cinemas[i].Movie.title, title) == 0) 
      {
         printf("Cinema %d: %s\n", cinemas[i].Movie.numCinema, cinemas[i].Movie.title);
         for (j = 0; j < MAX_SHOWINGS; j++) 
         {
            if (strlen(cinemas[i].show[j].showingTime) > 0) 
            {
               printf("\tShow Time: %s\n", cinemas[i].show[j].showingTime);
               printf("\tAvailable Seats: %d\n\n", MAX_SEATS - cinemas[i].show[j].seatsTaken);
            }
         }
      }
   }
}

/* searchTime searches for a specific show time across all cinemas and displays matching details.
@param time - pointer to a string containing the show time to search for
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
searchTime(char *time)
{
   int i, j;
   
   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      for (j = 0; j < MAX_SHOWINGS; j++) 
      {
         if (strlen(cinemas[i].show[j].showingTime) > 0 && strcmp(cinemas[i].show[j].showingTime, time) == 0) 
         {
            printf("Cinema %d: %s\n", cinemas[i].Movie.numCinema, cinemas[i].Movie.title);
            printf("  Show Time: %s\n", cinemas[i].show[j].showingTime);
            printf("  Available Seats: %d\n", MAX_SEATS - cinemas[i].show[j].seatsTaken);
         }
      }
   }
}

/* saveExit saves the current state of cinemas and their booked seats to a file.
@param filename - pointer to a string containing the filename to save data into
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
saveExit(char *filename)
{  
   int i, j, k, l;
   FILE *fp = fopen(filename, "w");

   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      for (j = 0; j < MAX_SHOWINGS; j++)
      {
         if (cinemas[i].show[j].seatsTaken > 0)
         {
            fprintf(fp, "Cinema No: %d\n", cinemas[i].Movie.numCinema);
            fprintf(fp, "Title: %s\n", cinemas[i].Movie.title);
            fprintf(fp, "Time: %s\n", cinemas[i].show[j].showingTime);
            fprintf(fp, "Taken Seats:\n");
            
            for (k = 0; k < 5; k++) 
            {
               for (l = 0; l < 10; l++) 
               {   
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
   fclose(fp);
}

int main() 
{
   int choice;
   str filename, date;
   char title[31], time[31];
   
   preLoadSched("MovieSched.txt");
   
   printf("Enter Date Today(dd-mm-yyyy): "); // for save on exit function
   scanf(" %[^\n]s", date);
   
   strcpy(filename, "show-");
   strcat(filename, date);
   strcat(filename, ".txt"); //finalize filename with ".txt" as file extension

   do
   {   
      printf("\n===== Main Menu =====\n");
      printf("1. Load Schedule\n");
      printf("2. View Schedule\n");
      printf("3. Select Seats\n");
      printf("4. Search Movie\n");
      printf("5. Search Time\n");
      printf("6. Save and Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      getchar(); // Consume newline left by scanf
      
      switch (choice) 
      {
         case 1:
            loadSched();
            printf("Schedule loaded successfully!\n");
            break;
         case 2:
            viewSched(); // view available schedule
            break;
         case 3:
            selectSeat(); // select seats
            break;
         case 4:
            printf("Enter Movie Title: ");
            scanf(" %[^\n]s", title);
            searchTitle(title); // search movie by title
            break;
         case 5:
            printf("Enter Show Time: ");
            scanf(" %[^\n]s", time);
            searchTime(time); // search movie by time
            break;
         case 6:
            saveExit(filename); 
            printf("Schedule saved successfully! Exiting program.\n");
            break;
         default:
            printf("Invalid choice! Please enter a valid number.\n");
            break;
      }
   } while (choice != 6); // Continue until the user chooses to exit
   
   return 0;
}

