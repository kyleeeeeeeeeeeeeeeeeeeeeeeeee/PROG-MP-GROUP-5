void 
searchTimeRange()
{
	int i, j, k=-1;
    int nShowHr, nShowMin, nValid = 0;
    int nStartHr, nStartMin, nEndHr, nEndMin;
    char cStartPeriod, cEndPeriod;
    struct TimeRangeTag range[36];
    struct TimeRangeTag temp;
    string pStartTime, pEndTime;
  
    printf("\nEnter Start Time: ");
   scanf(" %[^\n]s", pStartTime);
   printf("\nEnter End Time: ");
   scanf(" %[^\n]s", pEndTime);

	while (!nValid)
	{
    	// Convert start and end times to minutes since midnight]
    	sscanf(pStartTime, "%d:%d %c", &nStartHr, &nStartMin, &cStartPeriod);
    	sscanf(pEndTime, "%d:%d %c", &nEndHr, &nEndMin, &cEndPeriod);
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
                  k++;
                  range[k].Number = arrCinemas[i].sMovie.nNumCinema;
                  strcpy(range[k].Title, arrCinemas[i].sMovie.strTitle);
                  strcpy(range[k].Time, arrCinemas[i].arrShow[j].strShowTime);
                  range[k].Seats = MAX_SEATS - arrCinemas[i].arrShow[j].nTakenSeats;
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
   for(i = 0; i < MAX_CINEMAS - 1; i++)
   {
      for(j = i + 1; j < MAX_SHOWINGS; j++)
      {
         if(range[i].Time[5] == range[j].Time[5]){
            if(range[j].Time[1] < range[i].Time[1]){
               if (range[i].Time[1] != '0'){
                  temp = range[j];
                  range[j] = range[i];
                  range[i] = temp;

               }
            }
         }
         else{
            if(range[j].Time[5] < range[i].Time[5]){
                  temp = range[j];
                  range[j] = range[i];
                  range[i] = temp;
            }
         }
      }
   }
   

   for (i=0; i<MAX_SHOWINGS*2;i++){
      if(strlen(range[i].Time) > 1){
         printf("Cinema %d: %s\n\n", range[i].Number, range[i].Title);
         printf("   Show Time: %s\n", range[i].Time);
         printf("   Available Seats: %d\n\n", range[i].Seats);
      }

   }

}
