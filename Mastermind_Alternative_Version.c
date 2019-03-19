#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

// Declaration of functions
void strEqStr(char a[], char b[], int* same, int* positions, int s);
void tostring(char str[], int num, int len);

//////////////////////////////
//////////MAIN_START//////////
//////////////////////////////
int main(int argc, char *argv[])
{	// 1.
	srand(time(NULL)); // initialization of rand()
	printf("\nWelcome to the secret number game!\n");
	printf("How many digits do you want to use [3,5].\n");
	int n,i;
	do
	{   // checking for right input
		scanf("%d",&n);
	    if((n<3)||(n>5))
	    {
	    	printf("The number you gave is out of bounds. :)\n"); 
	        printf("Give number of digits between [3,5].\n");
        }
	}while((n<3)||(n>5)); 
	
	// 2.
	// Determining the repetition of the digits of the secret number	
	int enable_duplicate;  // flag that is enabled if the dublicates are allowed
	char ch;	
	printf("Do you want to allow duplicate digits (y/n)?\n"); 
    ch=getch(); 
	if (ch == 'Y' || ch == 'y')
	{ // Case 1 : Dublicates are allowed
		enable_duplicate=1;
	}
	else 
	{ // Case 2 : Dublicated are not allowed
	    enable_duplicate=0;
	}
    
    // 3.
    // Determining the secret number according to the choices of the user    
    int secretnum;    
    char* str;
    if(n==3)  // Case for n=3 digits
    {   
    	if(enable_duplicate==1)  
    	{  // Case 1 : Dublicates are allowed
    		secretnum=rand()%900 + 100; // creating a random 3-digits number in [100,999] 
    	    str=(char*)malloc(3 * sizeof(char)); // dynamic memory allocation using malloc function
    	   	tostring(str,secretnum,n); // calling the function tostring() in order to the secret number into string
    	}
    	else   
    	{  // Case 2 : Dublicated are not allowed
    		secretnum=rand()%900 + 100;	// same as before, creating a random 3-digits number in [100,999]		
            str=(char*)malloc(3 * sizeof(char)); // dynamic memory allocation using malloc function            
            tostring(str,secretnum,n); // calling the function tostring() in order to the secret number into string
            while(str[0]==str[1] || str[1]==str[2]) // checking for dublicates and recreating the secret number without them
            {
            	secretnum=rand()%900 + 100;
              	tostring(str,secretnum,n);
            }    
        }
    }
    else if(n==4)  // Similarly for n=4
    {
    	if(enable_duplicate==1)
    	{
    		secretnum=rand()%9000 + 1000;
    	   	str=(char*)malloc(3 * sizeof(char));
    	   	tostring(str,secretnum,n);
    	}
    	else
    	{
    		secretnum=rand()%9000 + 1000;			
            str=(char*)malloc(4 * sizeof(char));
            tostring(str,secretnum,n);
            while(str[0]==str[1] || str[1]==str[2] || str[2]==str[3])
            {
            	secretnum=rand()%9000 + 1000;
              	tostring(str,secretnum,n);
            }
		}
    }
    else // Similarly for n=5
    {
    	if(enable_duplicate==1)
    	{
    		secretnum=rand()%90000 + 10000;
    	    str=(char*)malloc(3 * sizeof(char));
    	    tostring(str,secretnum,n);
        }
        else
        {
            secretnum=rand()%90000 + 10000;			
            str=(char*)malloc(5 * sizeof(char));
            tostring(str,secretnum,n);
            while(str[0]==str[1] || str[1]==str[2] || str[2]==str[3] || str[3]==str[4])
            {
            	secretnum=rand()%9000 + 1000;
              	tostring(str,secretnum,n);
            }	
        }
    }
    char see_sec;
    printf("Do you want to see the secret number (y/n)?\n");
    see_sec=getch();
    if (see_sec == 'Y' || see_sec == 'y')
	{
		printf("The secret number is: %d\n\n",secretnum);
	}

    // 4.
    // Determining the guess number of the player according to his choices above
    int tries=0;  // tryals
    int guess,div,count,end=0;
    printf("Give your guess (negative to quit): ");
    scanf("%d", &guess);
    if(guess<0)
	{
		printf("The player quitted.");
	  	return 0; //EXIT
    }
	while(guess>=0 && end!=1) // iterating until the user quits or finds the secret number
	{ 
    	tries++;
    	count=0;
    	div=guess;
    	while(div!=0) // counting the number of digits in the guess number
    	{	
      		div/=10;
      		++count;
    	}    

    	while(count!=n)  // while number of digits != n
    	{
    		count=0;
    		printf("Give correct guess number.");
    		scanf("%d", &guess);
    		div=guess;
    		while(div!=0)
    		{
     	 		div/=10;
     	 		++count;
    		}
		}
    	int flag=0; // flag enabled if the guess number has dublicates
    	char* guesstr;
    	guesstr=(char*)malloc(count * sizeof(char)); // dynamic memory allocation using malloc function
    	tostring(guesstr,guess,n);  // calling the function tostring() in order to the secret number into string
    
    	for(i=0;i<count-1;i++)
    	{
    		if(guesstr[i]==guesstr[i+1])
			{ 
		 		flag=1;  // dublicates found
		 		break;
	    	}
    	}

    	if(count==3 && (enable_duplicate==0 && flag==1)) // Case for n=3 digits
    	{
      		count=0; // setting count = 0 in order to enter the loop at least once
      		while((enable_duplicate==0 && flag==1) || count !=3)
	  		{
	  	 		flag=0,count=0;
      	 		printf("Give correct guess number.");  //an exei bei se afthn thn while loop to programa shmainei oti o guess number tou xrhsth den plhrei
         		scanf("%d", &guess);                   //tis proypotheseis pou o idios eixe thesei pio prin opote tou zhtaw na ksanadwsei mexri na tis plhrei
         		tostring(guesstr,guess,n); // calling the function tostring() in order to the secret number into string
         		div=guess;    
         		while(div!=0) // counting the number of digits in the guess number 
         		{
            		div/=10;
            		++count;
         		}   
         		for(i=0;i<count-1;i++)
         		{
    	    		if(guesstr[i]==guesstr[i+1])
		    		{ 
		       			flag=1; // dublicates found
	       			}
         		}
	  		}
    	}
    	else if(count==4 && (enable_duplicate==0 && flag==1)) // Similarly for n=4
    	{
      		count=0;
      		while((enable_duplicate==0 && flag==1) || count !=4)
	  		{
	  	 		flag=0,count=0;
      	 		printf("Give correct guess number.");
         		scanf("%d", &guess);
         		tostring(guesstr,guess,n);
         		div=guess;
         		while(div!=0)
         		{
            		div/=10;
            		++count;
         		}   
         		for(i=0;i<count-1;i++)
         		{
    	    		if(guesstr[i]==guesstr[i+1])
		    		{ 
		       			flag=1;
	        		}
         		}
      		}
    	}	    
    	else if(count==5 && (enable_duplicate==0 && flag==1)) // Similarly for n=5
    	{
      		count=0;
      		while((enable_duplicate==0 && flag==1) || count !=5)
	  		{
	  	 		flag=0,count=0;
      	 		printf("Give correct guess number.");
         		scanf("%d", &guess);
         		tostring(guesstr,guess,n);
         		div=guess;
         		while(div!=0)
         		{
            		div/=10;
            		++count;
         		}   
         		for(i=0;i<count-1;i++)
         		{
    	    		if(guesstr[i]==guesstr[i+1])
		    		{ 
		       			flag=1;
	        		}
         		}
      		}
    	}
    
    	// 5.
    	// Checking for the guess number of the player and printing appropritate messages 
    	int same=0,positions=0;
    	strEqStr(str, guesstr, &same, &positions, count); // calling the function strEqStr in order to learn how many digits of the secret number was correct in player's guess    
    
    	// Printing messages 
    	if(same==count && positions==count) 
    	{
    		printf("Excellent! You found it!\n");
			end=1;   	
    	}
    	else if(same>(n/2) && positions>(n/2))
    	{
    		printf("You are in the right path!\n");
    	}
    	else if(same>(n/2) && positions<=(n/2))
    	{
    		printf("Good guess!\n");
    	}
    	else if(same<=(n/2))
    	{
    		printf("Not so good guess...\n");
    	}
    
    	printf("Total number of digits found: %d\n",same);
    	printf("Digits found in correct positions: %d\n\n",positions);
    
    	if(end!=1) // checking for new iteration
    	{
    		printf("Give your guess (negative to quit): ");
    		scanf("%d", &guess);
    		if(guess<0) 
			{
				printf("Secret number is: %d\n",secretnum);
				printf("Number of tries before quitting is %d.\n",tries);
	  			printf("The player quitted.");
	  			return 0; //EXIT
    		}
    	}
	}
 
 	// Printing the number of tryals and the secret number
	printf("Secret number found: %d\n",secretnum);
	printf("You found the secret number with %d guesses.\n",tries);
	return (EXIT_SUCCESS);	
} 
//////////////////////////////
///////////MAIN_END///////////
//////////////////////////////

// function strEqStr : checks how many digits the 2 strings have in common and what are their positions 
void strEqStr(char a[], char b[], int* same, int* positions, int s)
{
	char temp[s];
	int i,j;
    strcpy(temp,b); // copying the 2nd string to a temp string in order to not ruin the elements of the original string 
    for(i=0; i < s; i++) 
	{
      for(j = 0; j < s; j++) 
	  {
        if(a[i] == b[j]) // ckecking if 2 elements of the strings are the same using the temp stirng
		{                // changing the element of the temp string with the character '*' so that this element stayes out of the next checking
            *same = *same + 1;
            temp[j] = '*';
        }
      }
    }
	for(i=0;i<s;i++)
	{
	  if(a[i]==b[i]) *positions = *positions+1; 
    }                                       
}                                           

// function tostring : converts integer into string
void tostring(char str[], int num, int len)
{
    int i, rem, temp;
    temp = num;
    for (i = 0; i < len; i++)
    {
        rem = num % 10;  // quotient of the division of the number by 10 which is actually the last digit
        num = num / 10;  // dividing the number by 10 is like we can send away the last digit and in this way we can extract all the digits
        str[len - (i + 1)] = rem; // checking all the numbers we get from the string in reverse in order to have the string in the right order when the conversion ends
    }
    str[len] = '\0'; // inserting in the last position the character '\0' dedicating the end of the string
}
