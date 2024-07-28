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

struct sValidShowing 
{
	int nCinemaIndex;
	int nShowIndex;
	int nTotalMins;
	
};

/* displayTopMovies display the top 3 most watched movies for the day based 
on the taken seats.
@param none - This function does not have a parameter
@return void - This function does not return a value.
Pre-condition: arrCinemas must be properly initialized and populated with 
movie data and seats.
*/
void 
displayTopMovies()
{
   int i, j, nTemp, nValidMovies = 0;
   int arrTotalSeats[6] = {};
   struct sViewMovieTag temp;
   
   for (i = 0; i < MAX_CINEMAS; i++)
   {
      for (j = 0; j < MAX_SHOWINGS; j++)
      {
         arrTotalSeats[i] += arrCinemas[i].arrShow[j].nTakenSeats;
      }
      if (arrTotalSeats[i] > 0) 
	  {
        nValidMovies++;
      }
   }

   for (i = 0; i < MAX_CINEMAS - 1; i++)
   {
      for (j = i + 1; j < MAX_SHOWINGS; j++)
      {
         if (arrTotalSeats[j] > arrTotalSeats[i])
		 {
            nTemp = arrTotalSeats[j];
            arrTotalSeats[j] = arrTotalSeats[i];
            arrTotalSeats[i] = nTemp;

            temp = arrCinemas[j];
            arrCinemas[j] = arrCinemas[i];
            arrCinemas[i] = temp;
         }
            
      }
   }
   
   printf("\nTop %d most watched movies for the day:\n", nValidMovies);
   for (i = 0; i < nValidMovies && i < 3; i++)
   {
   	  printf("\n");
      printf("   %d. %s - %d seats taken\n", i + 1, arrCinemas[i].sMovie.strTitle, arrTotalSeats[i]);
   }
   if (nValidMovies == 0) 
   {
   		printf("\n");
		printf("   No movies to display.\n");
   }  
}

/* initializeTable initializes the seat labels for a cinema's show.
@param nIndex - index of the cinema
@param nIndex2 - index of the show
@return void - This function does not return a value.
Pre-condition: nIndex must be within the range of 0 to MAX_CINEMAS - 1,
nIndex2 must be within the range of 0 to MAX_SHOWINGS - 1.
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
Pre-condition: nIndex must be within the range of 0 to MAX_CINEMAS - 1,
nIndex2 must be within the range of 0 to MAX_SHOWINGS - 1.
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
Pre-condition: pFilename must be a valid file path, arrCinemas must be properly defined.
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
      printf("Data has been successfully pre-loaded!\n");
      fscanf(pFp, "%[^\n]\n", strLine);
      
      for (j = 0; j < 6; j++)
      {
         if (strlen(strLine) == 1)
         {
            nCinemaIndex = strLine[0] - 48; 
            if (nCinemaIndex > MAX_CINEMAS) 
            {
                    printf("Cinema index %d out of bounds!\n", nCinemaIndex);
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
Pre-condition: User must provide a valid filename, arrCinemas must be properly defined.
*/
void 
loadSched()
{
   int i, j = 0;
   int nCinemaIndex;
   string strLine;
   string strFilename;
   
   FILE *pFp; 
   printf("\nEnter filename: ");
   scanf("%s", strFilename);
   pFp = fopen(strFilename, "r");

   while (pFp == NULL) 
   {
   	  printf("\n");
      printf("   Unable to open file! Please input a valid filename.\n");
   	  printf("\nEnter filename: ");
      scanf("%s", strFilename);
      pFp = fopen(strFilename, "r");     
   }
   if (pFp != NULL)
   {
   	  printf("\n");
      printf("   Data has been successfully loaded!\n");
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
Pre-condition: arrCinemas must be properly initialized and populatd with movie and show
time data.
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
      else 
	  {
	  	i = MAX_CINEMAS;
	  	printf("\n");
	  	printf("   No schedule available!\n");	
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
Pre-condition: nTitle, nTime, nROw, nCol must be within valid ranges, arrCinemas
must be properly initialized and contain relevant movie and show data.
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
Pre-condition: arrCinemas must be properly initialized and populatd with movie and show
time data.
*/
void 
selectSeat()
{
   int nRow, nCol;
   int i, j, k = 0;
   int nValidTitle = 0;
   int nNumSeats, nTimeIndex, nAvailSeats;
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
      if (nValidTitle != 1)
      {
			printf("\n");
        	printf("   Invalid movie title! Please try again.\n");
	  }
   }
   
   printf("\nShowing times for %s:\n", arrCinemas[nTitleIndex].sMovie.strTitle);
   
   for (j = 0; j < 6; j++)
   {
   	  printf("\n");
      printf("\t%s", arrCinemas[nTitleIndex].arrShow[j].strShowTime);
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
               printf("\n");
               printf("   Sorry! All seats are taken.\n");
            }
            else if (arrCinemas[nTitleIndex].arrShow[i].nTakenSeats < 50)
            {
               nValidTime = 1;
               nTimeIndex = i;
               nAvailSeats = MAX_SEATS - arrCinemas[nTitleIndex].arrShow[i].nTakenSeats;
            }
         }
      }
      if (nValidTime != 1)
      {
            printf("\n");
        	printf("   Invalid showing time! Please try again.\n");
	  }
      
   } while (nValidTime != 1);
   
   displayTable(nTitleIndex, nTimeIndex);

	if (nAvailSeats >= 4)
	{
		do
  		{	
      		printf("\nEnter number of seats (1-4): ");
      		scanf("%d", &nNumSeats); 
      
      		if (!(nNumSeats > 0 && nNumSeats < 5))
      		{
      			printf("\n");
      			printf("   Invalid number of seats! Please try again.\n");
	  		}
   		} while (!(nNumSeats > 0 && nNumSeats < 5)); // can reserve up to 4 seats only
   	}
   	else if (nAvailSeats > 0 && nAvailSeats < 4)
   	{
   		do
  		{	
      		printf("\nEnter number of seats (up to %d): ", nAvailSeats);
      		scanf("%d", &nNumSeats); 
      
      		if (!(nNumSeats > 0 && nNumSeats <= nAvailSeats))
      		{
      			printf("\n");
      			printf("   Invalid number of seats! Please try again.\n");
	  		}
   		} while (!(nNumSeats > 0 && nNumSeats <= nAvailSeats)); 
	}
   
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
      	 printf("\n");
         printf("   Seat taken! Please choose again.\n");
      }
    } while (!(k == nNumSeats));

    displayTable(nTitleIndex, nTimeIndex);
}

/* searchTitle searches for a movie title across all cinemas and displays its details.
@param *pTitle - pointer to a string containing the movie title to search for
@return void - This function does not return a value.
Pre-condition: arrCinemas must be properly initialized and populated with movie data.
*/
void 
searchTitle(char *pTitle)
{
   int i, j;
   int nValid = 0;

   while (!nValid)
   {
     printf("\nEnter movie title: ");
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
                 printf("   Showing time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
                 printf("   Available seats: %d\n\n", MAX_SEATS - arrCinemas[i].arrShow[j].nTakenSeats);
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
@param *pStartTime - pointer to a string containing the start time of the range.
@param *pEndTime - pointer to a string containing the end time of the range.
@return void - This function does not return a value.
Pre-condition: arrCinemas must be properly initialized and populated with show time data.
*/
void 
searchTimeRange(char *pStartTime, 
				char *pEndTime)
{
							
	int i, j, cinemaId, showId;
    int nStartHr, nStartMin, nEndHr, nEndMin;
    int nShowHr, nShowMin, nValid = 0, nCount = 0;
    char cWord[3], cWord2[3];
    struct sValidShowing arrValidShows[MAX_CINEMAS * MAX_SHOWINGS];
    struct sValidShowing temp;
    
	while (!nValid)
	{
    	// Convert start and end times to minutes since midnight
    	sscanf(pStartTime, "%d:%d %s", &nStartHr, &nStartMin, cWord);

		if (strcmp(cWord, "pm") == 0 && nStartHr != 12)
		{
				nStartHr += 12;
		}
		else if (strcmp(cWord, "am") == 0 && nStartHr == 12)
		{
				nStartHr = 0;
    	}

		nStartMin += nStartHr * 60;
    	sscanf(pEndTime, "%d:%d %s", &nEndHr, &nEndMin, cWord2);

		if (strcmp(cWord2, "pm") == 0 && nEndHr != 12)
	    {
				nEndHr += 12;
    	}
		else if (strcmp(cWord2, "am") == 0 && nEndHr == 12)
    	{
				nEndHr = 0;
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
					sscanf(arrCinemas[i].arrShow[j].strShowTime, "%d:%d %s", &nShowHr, &nShowMin, cWord);

					if (strcmp(cWord, "pm") == 0 && nShowHr != 12)
            		{
							nShowHr += 12;
            		}
					else if (strcmp(cWord, "am") == 0 && nShowHr == 12)
					{
							nShowHr = 0;			   	
            		}

					nShowMin += nShowHr * 60;

					if (nShowMin >= nStartMin && nShowMin <= nEndMin) 
            		{
            			arrValidShows[nCount].nCinemaIndex = i;
            			arrValidShows[nCount].nShowIndex = j;
            			arrValidShows[nCount].nTotalMins = nShowMin;
            			nCount++;
            			nValid = 1;
            		}
         		}
      		}		
   		}
		if (!nValid)
		{
			printf("   None! Please enter a new time range.\n");
            printf("\nStart time (hh:mm am/pm): ");
            scanf("%s", pStartTime);
            printf("\nEnd time (hh:mm am/pm): ");
            scanf("%s", pEndTime);
		}

		for (i = 0; i < nCount; i++)
		{
			for (j = i + 1; j < nCount; j++)
			{
				if (arrValidShows[i].nTotalMins > arrValidShows[j].nTotalMins)
				{
					temp = arrValidShows[i];
					arrValidShows[i] = arrValidShows[j];
					arrValidShows[j] = temp;
				}
			}
		}

		for (i = 0; i < nCount; i++)
		{
			cinemaId = arrValidShows[i].nCinemaIndex; 
			showId = arrValidShows[i].nShowIndex;

           	printf("Show Time: %s\n\n", arrCinemas[cinemaId].arrShow[showId].strShowTime);
			printf("   Cinema %d: %s\n", arrCinemas[cinemaId].sMovie.nNumCinema, arrCinemas[cinemaId].sMovie.strTitle);
            printf("   Available Seats: %d\n\n", MAX_SEATS - arrCinemas[cinemaId].arrShow[showId].nTakenSeats);
		}
	}
}

/* saveExit saves the current state of cinemas and their booked seats to a file.
@param pFilename - pointer to a string containing the filename to save data into
@return void - This function does not return a value.
Pre-condition: cinemas is a global structure with appropriate fields.
*/
void saveExit(char *pFilename)
{  
   int i, j, k, l;
   int arrTotalSeats[6] = {};
   FILE *pFp = fopen(pFilename, "w");

   for(i = 0; i < MAX_CINEMAS; i++)
   {
      for(j = 0; j < MAX_SHOWINGS; j++)
      {
         arrTotalSeats[i] += arrCinemas[i].arrShow[j].nTakenSeats;
      }
   }

   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      if (arrTotalSeats[i] > 0){
         if (i!=0)
            fprintf(pFp, "\n"); // for formatting purposes
            
         fprintf(pFp, "Cinema number: %d\n", arrCinemas[i].sMovie.nNumCinema);
         fprintf(pFp, "Title: %s\n", arrCinemas[i].sMovie.strTitle);
      }
      for (j = 0; j < MAX_SHOWINGS; j++)
      {
         if (arrCinemas[i].arrShow[j].nTakenSeats > 0)
         {
            fprintf(pFp, "Time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
            fprintf(pFp, "Taken seats:\n");
            
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
   int nChoice, nMovie, nChoice2, nDay, nMth, nYr, nValidDate = 0;
   string strFilename, strDate, strStartTime, strEndTime;
   string strTitle;
   
   preLoadSched("MovieSched.txt");
   
   do
   {
   		printf("\nEnter date today (dd-mm-yyyy): "); // for save on exit function
   		scanf(" %[^\n]s", strDate);
   		sscanf(strDate, "%d-%d-%d", &nDay, &nMth, &nYr);
   	   	
		if (nDay > 0 && nDay <= 31 && nMth > 0 && nMth <= 12 && nYr >= 2024 && nYr < 2035)
   		{
   			nValidDate = 1;
   		}
   		
   }  while (nValidDate == 0);
   
   strcpy(strFilename, "show-");
   strcat(strFilename, strDate);
   strcat(strFilename, ".txt"); //finalize filename with ".txt" as file extension

   do
   {   
      printf("\n===== Main Menu =====\n");
      printf("1. Load schedule\n");
      printf("2. View schedule\n");
      printf("3. Select seats\n");
      printf("4. Search movie\n");
      printf("5. Save and exit\n");
      printf("\nEnter your choice: ");
      scanf("%d", &nChoice);
      
      switch (nChoice) 
      {
         case 1:
            loadSched();
            break;
         case 2:
            viewSched(); // view available schedule
            break;
         case 3:
            selectSeat(); // select seats
            break;
         case 4: 
			nChoice2 = 0;
         	while (!nChoice2)
         	{
			    printf("\n1. Search movie by title\n");
      			printf("2. Search movie by time\n");
         		printf("\nEnter your choice: ");
      			scanf("%d", &nMovie);
      			
      			if (nMovie == 1) 
                {
                    searchTitle(strTitle);
					nChoice2 = 1; 
                }
                else if (nMovie == 2) 
                {
					printf("\nEnter Start Time (hh:mm am/pm): ");
	            	scanf(" %[^\n]s", strStartTime);
	            	printf("\nEnter End Time (hh:mm am/pm): ");
	            	scanf(" %[^\n]s", strEndTime);
	            	searchTimeRange(strStartTime, strEndTime); // search movie by time range
                    nChoice2 = 1;
                }
                else 
                {
                    printf("\n");
            		printf("   Invalid choice! Please enter a valid number.\n");
                }
			}
            break;
         case 5:
            saveExit(strFilename);
            displayTopMovies();
            printf("\nSchedule saved successfully! Exiting program.\n");
            break;
         default:
			printf("\n");
            printf("   Invalid choice! Please enter a valid number.\n");
            break;
      }
   } while (nChoice != 5); // Continue until the user chooses to exit
   
   return 0;
}
