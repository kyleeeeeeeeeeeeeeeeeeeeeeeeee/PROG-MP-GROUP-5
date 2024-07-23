/*********************************************************************************************************
This is to certify that this project is our own work, based on our personal efforts in studying and applying 
the concepts learned. We have constructed the functions and their respective algorithms and corresponding 
code by ourselves. The program was run, tested, and debugged by our own efforts. We further certify that we 
have not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
Jediaelle Denise De Castro, DLSU ID# 12308226
Kyle Gabriel A. Maristela, DLSU ID# 12307777
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>

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

struct sMovieData
{
    string strMovieTitle;
	int nTotalSeats;	
};

struct sViewMovieTag arrCinemas[MAX_CINEMAS]; // Array of cinema schedules

/* displayTopMovies display the top 3 most watched movies for the day based 
on the taken seats.
@param none - This function does not have a parameter
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
displayTopMovies()
{
   int i, j;
   int totalSeats[6] = {};
   struct sViewMovieTag temp;
   int nTemp;
   
   for(i = 0; i < MAX_CINEMAS; i++)
   {
      for(j = 0; j < MAX_SHOWINGS; j++)
      {
         totalSeats[i] += arrCinemas[i].arrShow[j].nTakenSeats;
      }
   }

   for(i = 0; i < MAX_CINEMAS - 1; i++)
   {
      for(j = i + 1; j < MAX_SHOWINGS; j++)
      {
         if(totalSeats[j] > totalSeats[i]){
            nTemp = totalSeats[j];
            totalSeats[j] = totalSeats[i];
            totalSeats[i] = nTemp;

            temp = arrCinemas[j];
            arrCinemas[j] = arrCinemas[i];
            arrCinemas[i] = temp;
         }
            
      }
   }
   
   printf("Top 3 most watched movies for the day:\n");
   for(i = 0; i < 3; i++)
   {
      printf("%d. %s - %d seats taken\n", i+1, arrCinemas[i].sMovie.strTitle, totalSeats[i]);
   }  
}

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
         switch (nRow) 
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
         
         switch (nCol) 
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
	
   printf("\n");	
   for (nRow = 0; nRow < 5; nRow++)
   {
      for (nCol = 0; nCol < 10; nCol++)
      {
         printf("%s ", arrCinemas[nIndex].arrShow[nIndex2].arrSeats[nRow][nCol]);
      }
      printf("\n");
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
   int i, j = 0;
   int nCinemaIndex;
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
      fscanf(pFp, "%[^\n]\n", strLine);
      
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
                    fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex-1].sMovie.strTitle);
                    fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex-1].sMovie.strDescription);
                    fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex-1].sMovie.strRunTime);
               
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
   int i, j = 0;
   int nCinemaIndex;
   string strLine;
   string strFilename;
   
   FILE *pFp; 
   printf("Enter filename: ");
   scanf("%s", strFilename);
   pFp = fopen(strFilename, "r");

   while (pFp == NULL) 
   {
      printf("Unable to open file. Please input filename again:\n");
      scanf("%s", strFilename);
      pFp = fopen(strFilename, "r");     
   }
   if (pFp != NULL)
   {
      printf("Data has been successfully imported\n");
      fscanf(pFp, "%[^\n]\n", strLine);
      
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
               arrCinemas[nCinemaIndex - 1].sMovie.nNumCinema = nCinemaIndex;
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strTitle);
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strDescription);
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strRunTime);
               
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
         printf("\nCinema %d: %s\n\n", arrCinemas[i].sMovie.nNumCinema, arrCinemas[i].sMovie.strTitle);
         for (j = 0; j < MAX_SHOWINGS; j++) 
         {
            if (strlen(arrCinemas[i].arrShow[j].strShowTime) > 0) 
            {
               printf("   Showing time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
            }
         }
      }
    }
}

/* printTicket creates and prints a ticket to a text file.
@param nTitle - index of the movie title in cinemas array
@param nTime - index of the show time in cinemas array
@param nNumSeats - number of seats in the cinema
@param nRow - row number of the seat
@param nCol - column number of the seat
@param nTicket - ticket number
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
printTicket(int nTitle, 
			int nTime, 
			int nNumSeats, 
			int nRow, 
			int nCol, 
			string strSeatName)
{
   string strFilename;
   FILE *pFp;
   char cTitle, cTime;

   strcpy(strFilename, "");   // clear filename
   strcpy(strFilename, "Cinema");
	
   cTitle = nTitle + 49;
   strFilename[6] = cTitle;
	
   strcat(strFilename, "_Show");
   cTime = nTime + 49;
	
   strFilename[12] = cTime;
   strcat(strFilename, strSeatName);  

   strcat(strFilename, ".txt");   //file extension (text file)
   pFp = fopen(strFilename, "w");
   
   if (strcmp(arrCinemas[nTitle].arrShow[nTime].arrSeats[nRow][nCol], "X") == 0)
   {
      fprintf(pFp, "%d\n", arrCinemas[nTitle].sMovie.nNumCinema);
      fprintf(pFp, "%s\n", arrCinemas[nTitle].sMovie.strTitle);
      fprintf(pFp, "%s\n", arrCinemas[nTitle].arrShow[nTime].strShowTime);
      fprintf(pFp, "%c%d\n", nRow + 65, nCol + 1);
    }
   fprintf(pFp, "\n");
   fclose(pFp);
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
   int nRow, nCol;
   int i, j, k = 0;
   int nValidTitle = 0;
   int nNumSeats, nTimeIndex;
   int nValidSeats = 0, nValid = 0;
   int nTitleIndex = 0, nValidTime = 0;
   string strTitle, strShowingTime, strSeats[3];
   string strSeatName;

   while (nValidTitle != 1)
   {
      printf("\nEnter movie title: ");
      scanf(" %[^\n]s", strTitle);
      
      for (i = 0; i < 6; i++)
      {
         if (strcmp(strTitle, arrCinemas[i].sMovie.strTitle) == 0)
         {
            nValidTitle = 1;
            nTitleIndex = i;
         }
      }
   }
   
   printf("\nShowing times for %s:\n", arrCinemas[nTitleIndex].sMovie.strTitle);
   
   for (j = 0; j < 6; j++)
   {
      printf("\n%s", arrCinemas[nTitleIndex].arrShow[j].strShowTime);
   }
   
   printf("\n");
   
   do
   {
      printf("\nEnter showing time: ");
      scanf(" %[^\n]s", strShowingTime);
      
      for (i = 0; i < 6; i++)
      {
         if (strcmp(arrCinemas[nTitleIndex].arrShow[i].strShowTime, strShowingTime) == 0)
         {
            if (arrCinemas[nTitleIndex].arrShow[i].nTakenSeats == 50)
            {
               printf("Sorry, all seats are taken.\n");
            }
            else if (arrCinemas[nTitleIndex].arrShow[i].nTakenSeats < 50)
            {
               nValidTime = 1;
               nTimeIndex = i;
            }
         }
      }
   } while (nValidTime != 1);
   
   displayTable(nTitleIndex, nTimeIndex);

   do
   {
      printf("\nEnter number of seats: ");
      scanf("%d", &nNumSeats); 
   } while (!(nNumSeats > 0 && nNumSeats < 5)); // can reserve up to 4 seats only
   
   do 
   {
      printf("\nEnter seat[%d]: ", k + 1);
      scanf("%s", strSeats[k]);

      for (i = 0; i < 5; i++)
      {
         for (j = 0; j < 10; j++)
         {
            if (strcmp(arrCinemas[nTitleIndex].arrShow[nTimeIndex].arrSeats[i][j], strSeats[k]) == 0)
            {
               strcpy(strSeatName, arrCinemas[nTitleIndex].arrShow[nTimeIndex].arrSeats[i][j]);   
               strcpy(arrCinemas[nTitleIndex].arrShow[nTimeIndex].arrSeats[i][j], "X");
               nValid = 1;
               nValidSeats++;
               nRow = i;
               nCol = j;
               k++;
               arrCinemas[nTitleIndex].arrShow[nTimeIndex].nTakenSeats++;
               i = i + 5;
               j = j + 10;
            }
         }
      }
      if (nValid == 1)
      { 
         nValid = 0;
         printTicket(nTitleIndex, nTimeIndex, nNumSeats, nRow, nCol, strSeatName); 
      }
      else if (nValid == 0)
      {
         printf("\nSeat taken! Please choose again.");
      }
    } while (!(k == nNumSeats));

    displayTable(nTitleIndex, nTimeIndex);
}


/* searchTitle searches for a movie title across all cinemas and displays its details.
@param *pTitle - pointer to a string containing the movie title to search for
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
searchTitle(char *pTitle)
{
   int i, j;
   int nValid = 0;

   while (!nValid)
   {
     printf("\nEnter Movie Title: ");
     scanf(" %[^\n]s", pTitle);
     
     for (i = 0; i < MAX_CINEMAS; i++) 
     {
        if (strlen(arrCinemas[i].sMovie.strTitle) > 0 && strcmp(arrCinemas[i].sMovie.strTitle, pTitle) == 0) 
        {
           nValid = 1;
           printf("\nCinema %d: %s\n\n", arrCinemas[i].sMovie.nNumCinema, arrCinemas[i].sMovie.strTitle);
           for (j = 0; j < MAX_SHOWINGS; j++) 
           {
              if (strlen(arrCinemas[i].arrShow[j].strShowTime) > 0) 
              {
                 printf("   Show Time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
                 printf("   Available Seats: %d\n\n", MAX_SEATS - arrCinemas[i].arrShow[j].nTakenSeats);
              }
           }
        }
     }
     if (!nValid)
     {
		printf("\n");
        printf("   Invalid movie title! Please try again.\n");
     }
   }
}

/*searchTimeRange searches for a specific show time, within the specified time range of the user, 
across all cinemas and displays matching details.
@param *pStartTime - pointer to a string containing the start time of the range
@param *pEndTime - pointer to a string containing the end time of the range
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
searchTimeRange(char *pStartTime, 
				char *pEndTime)
{
	int i, j;
    int nStartHr, nStartMin, nEndHr, nEndMin;
    int nShowHr, nShowMin, nValid = 0;
    char cStartPeriod, cEndPeriod;

	while (!nValid)
	{
    	// Convert start and end times to minutes since midnight
    	sscanf(pStartTime, "%d:%d %c", &nStartHr, &nStartMin, &cStartPeriod);
	
    	if (cStartPeriod == 'p')
    	{
			if (nStartHr != 12)
	    	{
				nStartHr += 12;
			}
		}
		else if (cStartPeriod == 'a')
		{
			if (nStartHr == 12)
	    	{
				nStartHr = 0;
		    }
    	}
	
		nStartMin += nStartHr * 60;
    	sscanf(pEndTime, "%d:%d %c", &nEndHr, &nEndMin, &cEndPeriod);
	
    	if (cEndPeriod == 'p' || cEndPeriod == 'P')
	    {
			if (nEndHr != 12)
			{
				nEndHr += 12;
			}
    	}
    	else if (cEndPeriod == 'a' || cEndPeriod == 'A')
    	{
			if (nEndHr == 12)
			{
				nEndHr = 0;
			}
    	}
    
		nEndMin += nEndHr * 60;
    	printf("\nAvailable show times from %s to %s:\n\n", pStartTime, pEndTime);
   
    	for (i = 0; i < MAX_CINEMAS; i++) 
    	{
			for (j = 0; j < MAX_SHOWINGS; j++) 
        	{
				if (strlen(arrCinemas[i].arrShow[j].strShowTime) > 0) 
            	{
					// Convert show time to minutes since midnight
					sscanf(arrCinemas[i].arrShow[j].strShowTime, "%d:%d %c", &nShowHr, &nShowMin, &cStartPeriod);
				
					if (cStartPeriod == 'p' || cStartPeriod == 'P')
            		{
						if (nShowHr != 12)
			   			{
							nShowHr += 12;
						}
            		}
					else if (cStartPeriod == 'a' || cStartPeriod == 'A')
					{
						if (nShowHr == 12)
						{
							nShowHr = 0;
			   			}
            		}
            
					nShowMin += nShowHr * 60;
            
					if (nShowMin >= nStartMin && nShowMin <= nEndMin) 
            		{
						nValid = 1;
						printf("Cinema %d: %s\n\n", arrCinemas[i].sMovie.nNumCinema, arrCinemas[i].sMovie.strTitle);
               			printf("   Show Time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
               			printf("   Available Seats: %d\n\n", MAX_SEATS - arrCinemas[i].arrShow[j].nTakenSeats);
            		}
         		}
      		}		
   		}
		if (!nValid)
		{
			printf("   None! Please enter a new time range.\n");
            printf("\nStart time: ");
            scanf("%s", pStartTime);
            printf("\nEnd time: ");
            scanf("%s", pEndTime);
		}
	}
}

/* saveExit saves the current state of cinemas and their booked seats to a file.
@param pFilename - pointer to a string containing the filename to save data into
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void 
saveExit(char *pFilename)
{  
   int i, j, k, l;
   FILE *pFp = fopen(pFilename, "w");

   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      for (j = 0; j < MAX_SHOWINGS; j++)
      {
         if (arrCinemas[i].arrShow[j].nTakenSeats > 0)
         {
            fprintf(pFp, "Cinema No: %d\n", arrCinemas[i].sMovie.nNumCinema);
            fprintf(pFp, "Title: %s\n", arrCinemas[i].sMovie.strTitle);
            fprintf(pFp, "Time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
            fprintf(pFp, "Taken Seats:\n");
            
            for (k = 0; k < 5; k++) 
            {
               for (l = 0; l < 10; l++) 
               {   
                  if (strcmp(arrCinemas[i].arrShow[j].arrSeats[k][l], "X") == 0) 
                  { 
                     // Seat identifier ex: A1, B2 
                     fprintf(pFp, "%c%d, ", 'A' + k, l + 1);
                  }
               } 
            }
            fprintf(pFp, "\n\n"); // for formatting purposes
         }
      }
   }
   fclose(pFp);
}

int main() 
{
   int nChoice;
   string strFilename, strDate;
   string strTitle, strStartTime, strEndTime;;
   
   preLoadSched("MovieSched.txt");
   
   printf("\nEnter Date Today(dd-mm-yyyy): "); // for save on exit function
   scanf(" %[^\n]s", strDate);
   
   strcpy(strFilename, "show-");
   strcat(strFilename, strDate);
   strcat(strFilename, ".txt"); //finalize filename with ".txt" as file extension

   do
   {   
      printf("\n===== Main Menu =====\n");
      printf("1. Load Schedule\n");
      printf("2. View Schedule\n");
      printf("3. Select Seats\n");
      printf("4. Search Movie\n");
      printf("5. Search Time\n");
      printf("6. Save and Exit\n");
      printf("\nEnter your choice: ");
      scanf("%d", &nChoice);
      getchar(); // Consume newline left by scanf
      
      switch (nChoice) 
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
            searchTitle(strTitle); // search movie by title
            break;
         case 5:
            printf("\nEnter Start Time: ");
            scanf(" %[^\n]s", strStartTime);
            printf("\nEnter End Time: ");
            scanf(" %[^\n]s", strEndTime);
            searchTimeRange(strStartTime, strEndTime); // search movie by time range
            break;
         case 6:
            saveExit(strFilename);
            displayTopMovies();
            printf("Schedule saved successfully! Exiting program.\n");
            break;
         default:
			printf("\n");
            printf("   Invalid choice! Please enter a valid number.\n");
            break;
      }
   } while (nChoice != 6); // Continue until the user chooses to exit
   
   return 0;
}

