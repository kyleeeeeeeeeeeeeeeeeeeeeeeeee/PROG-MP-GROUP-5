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

// Maximum limits for cinemas, showings, and seats
#define MAX_CINEMAS 6
#define MAX_SHOWINGS 6
#define MAX_SEATS 50

// Custom string types
typedef char longString[101];
typedef char string[31];

// Structure to represent a movie
struct sMovieTag
{
   int nNumCinema;
   string strTitle;
   longString strDescription;
   string strRunTime;
};

// Structure to represent a show
struct sShowTag
{
    string strShowTime;
    string arrSeats[5][10];
    int nTakenSeats;
};

// Structure to represent a movie showing (1 showing time = 1 cinema)
struct sViewMovieTag 
{    
    struct sMovieTag sMovie;
    struct sShowTag arrShow[MAX_SHOWINGS];
};

// Structure to represent movie data
struct sMovieData
{
    string strMovieTitle;
	int nTotalSeats;	
};

// Structure to represent a valid showing
struct sValidShowing 
{
	int nCinemaIndex;
	int nShowIndex;
	int nTotalMins;
};

// Array of cinema schedules
struct sViewMovieTag arrCinemas[MAX_CINEMAS]; 

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
	int i, j, nTemp; 
	int nValidMovies = 0; 
	int arrTotalSeats[6] = {}; // Initialize array to store total seats
	
	struct sViewMovieTag sTemp; // Temporary structure to swap movies
   
    // Calculate total seats for each cinema
    for (i = 0; i < MAX_CINEMAS; i++)
    {
		for (j = 0; j < MAX_SHOWINGS; j++)
		{
         	arrTotalSeats[i] += arrCinemas[i].arrShow[j].nTakenSeats; // Add taken seats to total
		}
		
		if (arrTotalSeats[i] > 0) // Check if cinema has any taken seats
	    {
			nValidMovies++; // Increment valid movie count
        }
    } 

    // Sort cinemas by total seats in descending order
   	for (i = 0; i < MAX_CINEMAS - 1; i++)
    {
		for (j = i + 1; j < MAX_SHOWINGS; j++)
        {
			if (arrTotalSeats[j] > arrTotalSeats[i]) // Check if current cinema has more seats than next
		    {
				nTemp = arrTotalSeats[j]; // Swap total seats
            	arrTotalSeats[j] = arrTotalSeats[i];
            	arrTotalSeats[i] = nTemp;

	            sTemp = arrCinemas[j]; // Swap cinema structures
	            arrCinemas[j] = arrCinemas[i];
	            arrCinemas[i] = sTemp;
	        }           
      	}
   	}
   
   	// Display top 3 most watched movies
	printf("\nTop %d most watched movies for the day:\n", nValidMovies);
	
	for (i = 0; i < nValidMovies && i < 3; i++)
    {
		printf("\n");
      	printf("   %d. %s - %d seats taken\n", i + 1, arrCinemas[i].sMovie.strTitle, arrTotalSeats[i]); // Display movie title and seats taken
   	}
   
   	if (nValidMovies == 0) // Check if no movies have been watched
   	{
		printf("\n");
		printf("   No movies to display.\n"); // Display message if no movies have been watched
   	}  
}

/* initializeTable initializes the seat labels for a cinema's show.
@param nIndex - index of the cinema, must be within the range of 0 to MAX_CINEMAS - 1
@param nIndex2 - index of the show, must be within the range of 0 to MAX_SHOWINGS - 1
@return void - This function does not return a value.
Pre-condition: arrCinemas must be properly initialized and be enough to store nIndex and nIndex2.
*/
void 
initializeTable(int nIndex, 
                int nIndex2)
{
   int nRow, nCol; // Loop counters for rows and columns.
   
   // Iterate over each row in the seating table.
   for (nRow = 0; nRow < 5; nRow++)
   {
   	  // Iterate over each column in the seating table.
      for (nCol = 0; nCol < 10; nCol++)
      {
      	 // Determine the row letter (A-E) based on the row index and set it as the seat label.
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
         
         // Determine the column number (1-10) based on the column index and append it to the seat label.
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
Pre-condition: arrCinemas must be properly initialized, nIndex must be within the range 
of 0 to MAX_CINEMAS - 1, and nIndex2 must be within the range of 0 to MAX_SHOWINGS - 1
*/
void 
displayTable(int nIndex, 
             int nIndex2)
{
   int nRow, nCol; // Loop counters for rows and columns.
	
   printf("\n");
   	
   // Iterate over each row in the seating table.
   for (nRow = 0; nRow < 5; nRow++)
   {
   	  // Iterate over each column in the seating table.
      for (nCol = 0; nCol < 10; nCol++)
      {
      	 // Print the seat label, followed by a space.
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
   int i, j = 0; // Loop counters.
   int nCinemaIndex; // Index of the current cinema.
   string strLine; // USed to hold a line from the file.
   
   // Open the file for reading.
   FILE *pFp; 
   pFp = fopen(pFilename, "r");
   
   // Check if the file was opened successfully.
   if (pFp == NULL) 
   {
      // Print an error message if the file could not be opened.
      printf("Unable to open file: %s\n", pFilename);
   }   
   else
   {
      // Print a success message if the file was opened.
      printf("Data has been successfully pre-loaded!\n");
      
      // Read the first line from the file (should be a cinema index).
      fscanf(pFp, "%[^\n]\n", strLine);
      
      // Iterate over each cinema in the file.
      for (j = 0; j < 6; j++)
      {
         // Check if the current line is a cinema index.
         if (strlen(strLine) == 1)
         {
            // Convert the cinema index from a character to an integer.
            nCinemaIndex = strLine[0] - 48; 
            
            // Check if the cinema index is within bounds.
            if (nCinemaIndex > MAX_CINEMAS) 
            {
               // Print an error message if the cinema index is out of bounds.
               printf("Cinema index %d out of bounds!\n", nCinemaIndex);
               
               // Close the file.
               fclose(pFp);
            }
            
            else if (nCinemaIndex > 0 && nCinemaIndex < 7)
            {
               // Set the cinema number in the cinema struct.
               arrCinemas[nCinemaIndex - 1].sMovie.nNumCinema = nCinemaIndex;
               
               // Read the movie title, description, and runtime from the file.
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strTitle);
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strDescription);
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strRunTime);
               
               // Iterate over each showing for the current cinema.
               for (i = 0; i < MAX_SHOWINGS + 1; i++) 
               {
                  // Read the showtime from the file.
                  fscanf(pFp, "%30[^\n]\n", strLine);
                  
                  // Check if the showtime is valid (not a single character).
                  if (strlen(strLine) > 1)
                  {
                     // Set the showtime in the showing struct.
                     strcpy(arrCinemas[nCinemaIndex - 1].arrShow[i].strShowTime, strLine);
                     
                     // Initialize the seating table for the current showing.
                     initializeTable(nCinemaIndex - 1, i);
                  }
                  
                  else 
                  {
                     // If the showtime is not valid, skip to the next cinema.
                     i += MAX_SHOWINGS;
                  }
               }
            }
         }  
      }
   }
   
   // Close the file.
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
   int i, j = 0; // Loop counters.
   int nCinemaIndex; // Index of the current cinema.
   
   string strLine; // USed to hold a line from the file.
   string strFilename; // Name of the file to load from.

   FILE *pFp; 
   
   // Prompt the user to enter a filename.
   printf("\nEnter filename: ");
   scanf("%s", strFilename);
   
   // Open the file for reading.
   pFp = fopen(strFilename, "r");

   // Continue to prompt the user for a filename until a valid file is entered.
   while (pFp == NULL) 
   {
   	  printf("\n");
      printf("   Unable to open file! Please input a valid filename.\n");
      
   	  printf("\nEnter filename: ");
      scanf("%s", strFilename);
      
      pFp = fopen(strFilename, "r");     
   }
   
   // If the file was opened successfully, load the data.
   if (pFp != NULL)
   {
   	  printf("\n");
      printf("   Data has been successfully loaded!\n");
      
      // Read the first line from the file (should be a cinema index).
      fscanf(pFp, "%[^\n]\n", strLine);
      
      // Iterate over each cinema in the file.
      for (j = 0; j < 6; j++)
      {
         // Check if the current line is a cinema index.
         if (strlen(strLine) == 1)
         {
            // Convert the cinema index from a character to an integer.
            nCinemaIndex = strLine[0] - 48;
            
            // Check if the cinema index is within bounds.
            if (nCinemaIndex > MAX_CINEMAS) 
            {
               // Print an error message if the cinema index is out of bounds.
               printf("Cinema index %d out of bounds\n", nCinemaIndex);
               
               // Close the file.
               fclose(pFp);
            } 
			 
            else if (nCinemaIndex > 0 && nCinemaIndex < 7)
            {
               // Set the cinema number in the cinema struct.
               arrCinemas[nCinemaIndex - 1].sMovie.nNumCinema = nCinemaIndex;
               
               // Read the movie title, description, and runtime from the file.
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strTitle);
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strDescription);
               fscanf(pFp, "%[^\n]\n", arrCinemas[nCinemaIndex - 1].sMovie.strRunTime);
               
               // Iterate over each showing for the current cinema.
               for (i = 0; i < MAX_SHOWINGS + 1; i++) 
               {
                  // Read the showtime from the file.
                  fscanf(pFp, "%30[^\n]\n", strLine);
                  
                  // Check if the showtime is valid (not a single character).
                  if (strlen(strLine) > 1) 
                  {
                     // Set the showtime in the showing struct.
                     strcpy(arrCinemas[nCinemaIndex - 1].arrShow[i].strShowTime, strLine);
                     
                     // Initialize the seating table for the current showing.
                     initializeTable(nCinemaIndex - 1, i);
                  }
                  
                  else 
                  {
                     // If the showtime is not valid, skip to the next cinema.
                     i += MAX_SHOWINGS;
                  }
               }
            }
         }  
      }
   }
   
   // Close the file.
   fclose(pFp);
}

/* viewSched displays the schedule of movies and their show times for each cinema.
@param none - This function does not have a parameter
@return void - This function does not return a value.
Pre-condition: arrCinemas must be properly initialized and populated with movie and show
time data.
*/
void 
viewSched()
{
   int i, j; // Loop counters.
   
   // Iterate through each cinema.
   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      // Check if the cinema has a movie scheduled.
      if (strlen(arrCinemas[i].sMovie.strTitle) > 0) 
      {
         // Print the cinema number and movie title.
         printf("\nCinema %d: %s\n\n", arrCinemas[i].sMovie.nNumCinema, arrCinemas[i].sMovie.strTitle);
         
         // Iterate through each showing for the current cinema.
         for (j = 0; j < MAX_SHOWINGS; j++) 
         {
            // Check if the showing has a scheduled time.
            if (strlen(arrCinemas[i].arrShow[j].strShowTime) > 0) 
            {
               // Print the showing time.
               printf("   Showing time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
            }
         }
      }
      
      else 
	  {
	  	// If no schedule is available, print a message.
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
   string strFilename; // The filename to print the ticket to.
   char cTitle, cTime; // Characters to represent the cinema and showtime in the filename.
   
   FILE *pFp; 

   // Clear the filename and set it to "Cinema".
   strcpy(strFilename, "");   
   strcpy(strFilename, "Cinema");
	
   // Convert the cinema index to a character.
   cTitle = nTitle + 49;
   strFilename[6] = cTitle;
	
   // Append "_Show" to the filename.
   strcat(strFilename, "_Show");
   
   // Convert the showtime index to a character.
   cTime = nTime + 49;
   strFilename[12] = cTime;
   
   // Append the seat name to the filename.
   strcat(strFilename, strSeatName);  

   // Append the file extension (".txt") to the filename.
   strcat(strFilename, ".txt");   
   
   // Open the file for writing.
   pFp = fopen(strFilename, "w");
   
   // Check if the seat is marked as occupied (put "X").
   if (strcmp(arrCinemas[nTitle].arrShow[nTime].arrSeats[nRow][nCol], "X") == 0)
   {
      // Print the cinema number, movie title, showtime, and seat number to the file.
      fprintf(pFp, "%d\n", arrCinemas[nTitle].sMovie.nNumCinema);
      fprintf(pFp, "%s\n", arrCinemas[nTitle].sMovie.strTitle);
      
      fprintf(pFp, "%s\n", arrCinemas[nTitle].arrShow[nTime].strShowTime);
      fprintf(pFp, "%c%d\n", nRow + 65, nCol + 1);
    }
   
   fprintf(pFp, "\n");
   
   // Close the file.
   fclose(pFp);
}

/* selectSeat prompts the user to select a movie, showing time, and seats, 
then reserves the selected seats.
@param none - This function does not have a parameter
@return void - This function does not return a value.
Pre-condition: arrCinemas must be properly initialized and populated with movie and show
time data.
*/
void 
selectSeat()
{
   int nRow, nCol;
   int i, j, k = 0;
   
   int nNumSeats, nAvailSeats;
   int nTimeIndex, nTitleIndex = 0;
   
   int nValidTitle = 0, nValidTime = 0;
   int nValidSeats = 0, nValidTake = 0;
   
   string strTitle, strShowingTime, strSeats[3];
   string strSeatName;

   // Loop until a valid movie title is entered
   while (nValidTitle != 1)
   {
      printf("\nEnter movie title: ");
      scanf(" %[^\n]s", strTitle);
      
      // Check if the entered title matches any of the available movies
      for (i = 0; i < 6; i++)
      {
         if (strcmp(strTitle, arrCinemas[i].sMovie.strTitle) == 0)
         {
            nValidTitle = 1;
            nTitleIndex = i;
         }
      }
      
      // Display error message if the title is invalid
      if (nValidTitle != 1)
      {
			printf("\n");
        	printf("   Invalid movie title! Please try again.\n");
	  }
   }
   
   // Display the showing times for the selected movie
   printf("\nShowing times for %s:\n", arrCinemas[nTitleIndex].sMovie.strTitle);
   
   for (j = 0; j < 6; j++)
   {
   	  printf("\n");
      printf("\t%s", arrCinemas[nTitleIndex].arrShow[j].strShowTime);
   }
   
   printf("\n");
   
   // Loop until a valid showing time is entered
   do
   {
      printf("\nEnter showing time: ");
      scanf(" %[^\n]s", strShowingTime);
      
      // Check if the entered showing time matches any of the available times
      for (i = 0; i < 6; i++)
      {
         if (strcmp(arrCinemas[nTitleIndex].arrShow[i].strShowTime, strShowingTime) == 0)
         {
            // Check if all seats are taken for the selected showing time
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
      
      // Display error message if the showing time is invalid
      if (nValidTime != 1)
      {
            printf("\n");
        	printf("   Invalid showing time! Please try again.\n");
	  }
      
   } while (nValidTime != 1);
   
   // Display the seat table for the selected showing time
   displayTable(nTitleIndex, nTimeIndex);

   // Ask for the number of seats to reserve
   if (nAvailSeats >= 4)
   {
      do
      { 
         printf("\nEnter number of seats (1-4): ");
         scanf("%d", &nNumSeats); 
      
         // Validate the entered number of seats
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
      
         // Validate the entered number of seats
         if (!(nNumSeats > 0 && nNumSeats <= nAvailSeats))
         {
            printf("\n");
            printf("   Invalid number of seats! Please try again.\n");
         }
         
      } while (!(nNumSeats > 0 && nNumSeats <= nAvailSeats)); 
   }
   
   // Loop until all seats are reserved
   do 
   {
      printf("\nEnter seat[%d]: ", k + 1);
      scanf("%s", strSeats[k]);

      // Check if the entered seat is available
      for (i = 0; i < 5; i++)
      {
	  	 for (j = 0; j < 10; j++)
         {
            if (strcmp(arrCinemas[nTitleIndex].arrShow[nTimeIndex].arrSeats[i][j], strSeats[k]) == 0)
            {
               // Mark the seat as reserved
               strcpy(strSeatName, arrCinemas[nTitleIndex].arrShow[nTimeIndex].arrSeats[i][j]);   
               strcpy(arrCinemas[nTitleIndex].arrShow[nTimeIndex].arrSeats[i][j], "X");
               
               nValidTake = 1;
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
      
      if (nValidTake == 1)
      { 
         nValidTake = 0;
         // Print the ticket for the reserved seat
         printTicket(nTitleIndex, nTimeIndex, nNumSeats, nRow, nCol, strSeatName); 
      }
      
      // Display error message if the seat is already taken
      else if (nValidTake == 0)
      {
         printf("\n");
         printf("   Seat taken! Please choose again.\n");
      }
      
    } while (!(k == nNumSeats));

    // Display the updated seat table
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
   int nValidTitle = 0;

   // Loop until a valid movie title is entered
   while (!nValidTitle)
   {
     printf("\nEnter movie title: ");
     scanf(" %[^\n]s", pTitle);
     
     // Search for the entered title in the list of cinemas
     for (i = 0; i < MAX_CINEMAS; i++) 
     {
        // Check if the title matches and the cinema has a valid title
        if (strlen(arrCinemas[i].sMovie.strTitle) > 0 && strcmp(arrCinemas[i].sMovie.strTitle, pTitle) == 0) 
        {
           nValidTitle = 1;
           
           // Display the cinema details
           printf("\nCinema %d: %s\n\n", arrCinemas[i].sMovie.nNumCinema, arrCinemas[i].sMovie.strTitle);
           
           // Display the showing times and available seats for the cinema
           for (j = 0; j < MAX_SHOWINGS; j++) 
           {
              // Check if the showing time is valid
              if (strlen(arrCinemas[i].arrShow[j].strShowTime) > 0) 
              {
                 printf("   Showing time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
                 printf("   Available seats: %d\n\n", MAX_SEATS - arrCinemas[i].arrShow[j].nTakenSeats);
              }
           }
        }
     }
     
     // Display error message if the title is invalid
     if (!nValidTitle)
     {
		printf("\n");
        printf("   Invalid movie title! Please try again.\n");
     }
   }
}

/*searchTimeRange searches for a specific show time, within the specified time range of the user, 
across all cinemas and displays matching details.
@param none - This function does not have a parameter.
@return void - This function does not return a value.
Pre-condition: arrCinemas must be properly initialized and populated with show time data.
*/
void 
searchTimeRange()
{
	int i, j;
	char cWord[3], cWord2[3];
	
    int nStartHr, nStartMin, nEndHr, nEndMin;
	int cinemaId, showId, nValidStart, nValidEnd;
    
    int nShowHr, nShowMin;
	int nValidRange = 0, nCount = 0;
    string strStartTime, strEndTime;
    
    struct sValidShowing arrValidShows[MAX_CINEMAS * MAX_SHOWINGS];
    struct sValidShowing sTemp;
    
	// Loop until a valid time range is entered
	while (!nValidRange)
	{	
		nValidStart = 0;
		nValidEnd = 0;
		
		// Continue asking user until valid start time is given
		do
		{
			// Prompt user to enter start time
			printf("\nEnter Start Time (hh:mm am/pm): ");
	    	scanf(" %[^\n]s", strStartTime);	
	    	
	    	// Parse start time
    		sscanf(strStartTime, "%d:%d %s", &nStartHr, &nStartMin, cWord);
    		
    		// Validate start time
    		if (nStartHr > 0 && nStartHr <= 12 && nStartMin >= 0 && nStartMin < 60 && (strcmp(cWord, "pm") == 0 || strcmp(cWord, "am") == 0))
    		{
    			nValidStart = 1;
			}
			
			else
			{
				// Display error message if start time is invalid
				printf("\n");
				printf("   Invalid input! Please enter a valid time.\n");
			}
		
		} while (!nValidStart);
		
		// Continue asking user until valid end time is given
		do
		{
			// Prompt user to enter end time
			printf("\nEnter End Time (hh:mm am/pm): ");
			scanf(" %[^\n]s", strEndTime);
			
			// Parse end time
			sscanf(strEndTime, "%d:%d %s", &nEndHr, &nEndMin, cWord2);
			
			// Validate end time
			if (nEndHr > 0 && nEndHr <= 12 && nEndMin >= 0 && nEndMin < 60 && (strcmp(cWord2, "pm") == 0 || strcmp(cWord2, "am") == 0))
			{
				nValidEnd = 1;
			}
			
			else
			{
				// Display error message if end time is invalid
				printf("\n");
				printf("   Invalid input! Please enter a valid time.\n");
			}
			
		} while (!nValidEnd);

		// Convert start and end times to minutes since midnight
		if (strcmp(cWord, "pm") == 0 && nStartHr != 12)
		{
				nStartHr += 12;
		}
		
		else if (strcmp(cWord, "am") == 0 && nStartHr == 12)
		{
				nStartHr = 0;
    	}

		nStartMin += nStartHr * 60;

		if (strcmp(cWord2, "pm") == 0 && nEndHr != 12)
	    {
				nEndHr += 12;
    	}
    	
		else if (strcmp(cWord2, "am") == 0 && nEndHr == 12)
    	{
				nEndHr = 0;
    	}

		nEndMin += nEndHr * 60;
		
		// Handle case where start time is in pm and end time is in am
		if (strcmp(cWord, "pm") == 0 && strcmp(cWord2, "am") == 0) 
		{
            nEndMin += 24 * 60; 
        }
		
    	printf("\nAvailable show times from %s to %s:\n\n", strStartTime, strEndTime);
    	
    	// Search for show times within the entered time range
    	for (i = 0; i < MAX_CINEMAS; i++) 
    	{
			for (j = 0; j < MAX_SHOWINGS; j++) 
        	{
				if (strlen(arrCinemas[i].arrShow[j].strShowTime) > 0) 
            	{
					// Convert show time to minutes since midnight
					sscanf(arrCinemas[i].arrShow[j].strShowTime, "%d:%d %s", &nShowHr, &nShowMin, cWord);

					if (strcmp(cWord, "pm") == 0 && nShowHr!= 12)
            		{
							nShowHr += 12;
            		}
            		
            		else if (strcmp(cWord, "am") == 0 && nShowHr == 12)
					{
							nShowHr = 0;			   	
            		}

					nShowMin += nShowHr * 60;
					
					// Handle case where show time is in am and start time is in pm
					if (strcmp(cWord, "am") == 0 && nStartMin > nEndMin && nShowMin < nStartMin) 
					{
                        nShowMin += 24 * 60; 
                    }

					// Check if show time is within the entered time range
					if (nShowMin >= nStartMin && nShowMin <= nEndMin) 
            		{
            			// Store the show time and cinema details in an array
            			arrValidShows[nCount].nCinemaIndex = i;
            			arrValidShows[nCount].nShowIndex = j;
            			arrValidShows[nCount].nTotalMins = nShowMin;
            			nCount++;
            			nValidRange = 1;
            		}
         		}
      		}		
   		}

		// Sort the show times from earliest to latest
		for (i = 0; i < nCount; i++)
		{
			for (j = i + 1; j < nCount; j++)
			{
				if (arrValidShows[i].nTotalMins > arrValidShows[j].nTotalMins)
				{
					sTemp = arrValidShows[i];
					arrValidShows[i] = arrValidShows[j];
					arrValidShows[j] = sTemp;
				}
			}
		}

		// Display the show times and cinema details
		for (i = 0; i < nCount; i++)
		{
			cinemaId = arrValidShows[i].nCinemaIndex; 
			showId = arrValidShows[i].nShowIndex;

           	printf("Show Time: %s\n\n", arrCinemas[cinemaId].arrShow[showId].strShowTime);
			printf("   Cinema %d: %s\n", arrCinemas[cinemaId].sMovie.nNumCinema, arrCinemas[cinemaId].sMovie.strTitle);
            printf("   Available Seats: %d\n\n", MAX_SEATS - arrCinemas[cinemaId].arrShow[showId].nTakenSeats);
		}
		
		// Display error message if no show times are found
		if (!nValidRange)
		{
			printf("   None! Please enter a new time range.\n");
		}
	}
}

/* saveExit saves the current state of cinemas and their booked seats to a file.
@param pFilename - pointer to a string containing the filename to save data into
@return void - This function does not return a value.
Pre-condition: arrCinemas must be properly initialized and populated with movie 
and show time data.
*/
void saveExit(char *pFilename)
{  
   int i, j, k, l;
   int arrTotalSeats[6] = {}; // Initialize an array to store the total number of seats for each cinema
   
   FILE *pFp = fopen(pFilename, "w"); // Open the file in write mode

   // Calculate the total number of seats for each cinema
   for(i = 0; i < MAX_CINEMAS; i++)
   {
      for(j = 0; j < MAX_SHOWINGS; j++)
      {
         arrTotalSeats[i] += arrCinemas[i].arrShow[j].nTakenSeats;
      }
   }

   // Write the cinema details to the file
   for (i = 0; i < MAX_CINEMAS; i++) 
   {
      if (arrTotalSeats[i] > 0)
	  { 
	  	 // Check if there are any taken seats for this cinema
         if (i != 0)
         {
         	fprintf(pFp, "\n"); // Add a newline for formatting purposes
		 }
            
         fprintf(pFp, "Cinema number: %d\n", arrCinemas[i].sMovie.nNumCinema);
         fprintf(pFp, "Title: %s\n", arrCinemas[i].sMovie.strTitle);
      }
      
      // Write the show details to the file
      for (j = 0; j < MAX_SHOWINGS; j++)
      {
         if (arrCinemas[i].arrShow[j].nTakenSeats > 0) // Check if there are any taken seats for this show
         {
            fprintf(pFp, "Time: %s\n", arrCinemas[i].arrShow[j].strShowTime);
            fprintf(pFp, "Taken seats:\n");
            
            // Write the taken seats to the file
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
            fprintf(pFp, "\n\n"); // Add a newline for formatting purposes
         }
      }
      
   }
   fclose(pFp); // Close the file
}

int main() 
{
   int nChoice, nChoice2, nMovie; 
   int nDay, nMth, nYr, nValidDate = 0;
   
   string strFilename, strDate, strTitle;

   // Preload movie schedule from file
   preLoadSched("MovieSched.txt");
   
   // Validate date input
   do
   {
   		printf("\nEnter date today (dd-mm-yyyy): "); // for save on exit function
   		scanf(" %[^\n]s", strDate);
   		
   		sscanf(strDate, "%d-%d-%d", &nDay, &nMth, &nYr);
   	   	
		// Check if date is within valid range
		if (nDay > 0 && nDay <= 31 && nMth > 0 && nMth <= 12 && nYr >= 2024 && nYr < 2035)
   		{
   			nValidDate = 1;
   		}
   		
		// Display error message if date is invalid
   		if (!nValidDate)
   		{
   			printf("\n");
   			printf("   Invalid input! Please enter valid date.\n");
		}
   		
   } while (!nValidDate);
   
   // Construct filename for saving schedule
   strcpy(strFilename, "show-");
   strcat(strFilename, strDate);
   strcat(strFilename, ".txt"); //finalize filename with ".txt" as file extension

   // Main menu loop
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
      
      // Handle user input
      switch (nChoice) 
      {
         case 1:
            loadSched(); // Load schedule from file
            break;
         case 2:
            viewSched(); // View available schedule
            break;
         case 3:
            selectSeat(); // Select seats
            break;
         case 4: 
			nChoice2 = 0;
			
			// Search movie submenu
         	while (!nChoice2)
         	{
			    printf("\n1. Search movie by title\n");
      			printf("2. Search movie by time\n");
         		printf("\nEnter your choice: ");
      			scanf("%d", &nMovie);
      			
      			// Handle search movie input
      			if (nMovie == 1) 
                {
                    // Search movie by title
                    searchTitle(strTitle);
					nChoice2 = 1; 
                }
                else if (nMovie == 2) 
                {
	            	// Search movie by time range
	            	searchTimeRange();
                    nChoice2 = 1;
                }
                else 
                {
                    // Display error message for invalid input
                    printf("\n");
            		printf("   Invalid choice! Please enter a valid number.\n");
                }
			}
            break;
         case 5:
            // Save schedule and exit program
            saveExit(strFilename);
            displayTopMovies();
            printf("\nSchedule saved successfully! Exiting program.\n");
            break;
         default:
			// Display error message for invalid input
			printf("\n");
            printf("   Invalid choice! Please enter a valid number.\n");
            break;
      }
   } while (nChoice != 5); // Continue until the user chooses to exit
   
   return 0;
}
