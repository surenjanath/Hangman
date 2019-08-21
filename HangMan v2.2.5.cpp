/*


     ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
     || || ||||| |||||  |||| |||     ||||  |||  ||||| |||||  |||| |||||
     || || ||||| ||||| | ||| ||| |||||||| | | | ||||| ||||| | ||| |||||
     ||    |||| | |||| || || ||| ||  |||| ||  | |||| | |||| || || |||||
     || || |||     ||| ||| | ||| ||| |||| || || |||     ||| ||| | |||||
     || || || ||||| || ||||  |||     |||| ||||| || ||||| || ||||  ||||| 
     ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


                    		H A N G M A N


 ---------------
	CONTENTS
 ---------------
 0. LOAD LIBRARIES	
 1. LOAD WORDS
 2. LOAD GRAPHIC 
 3. GAME SIMULATION
 4. PROGRAM BACKBONE
*/

//LIBRARIES ARE NECCESSARY FOR EACH DIFFERENT FUNCTION USED OUTSIDE
#include<iostream> 
#include<fstream>	
#include<string>
#include<cstring>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
	
	
void setColor(unsigned short color) {
 HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hcon, color);
}	
/*	
 Color : 1 Blue
 Color : 2 green
 Color : 3 red
 Color : 4 purple
 Color : 5 orange
 Color : 6 white
 Color : 7 grey
 Color : 8 
 Color : 9
 Color : 10 neongreen
 Color : 11 skyblue
 Color : 12 pink
 Color : 13
 Color : 14
	*/
	
//******************************************************************************************
//						L O A D   W O R D S
//******************************************************************************************	
	struct WORDS{   	//This struct is to hold the characters from the string that is being loaded
		char Word[25];	//Letters of the word is being placed as characters in the array 
		int Amt;   		// This is to keep track of how many letters are there in the word.
	};
//******************************************************************************************			
bool isLowerCaseLetter (char c) {  							//Condition to take lower case. 
			  if (c >= 'a' && c <= 'z')
			          return true;
					    return false;
					}
										
	bool isUpperCaseLetter (char c) {						//Condition to take upper case. 
		   if (c >= 'A' && c <= 'Z')
		     return true;
			 return false;
					}
										
	bool isLetter(char ch) {								//Condition to take upper case. 
	   if (isUpperCaseLetter(ch) || isLowerCaseLetter(ch))
		      return true;
			  return false;
					}
					
bool isWord(char word[],int Amt){							//Condition to check whether array is a word.
	for (int i=0;i<Amt;i++){
	if (!isLetter(word[i]))
		return false;
	}	 
	 return true;
}

void selectionSort(WORDS arr[], int length){				//Function to sort the struct of array arr.
	
	int pos_min;
	WORDS temp;
	
	for(int i=0; i<length-1; i++){
		pos_min=i;
		temp=arr[i];  
		
	for (int j=i+1; j<length; j++)
	if (strcmp(arr[j].Word,temp.Word)<0){
		pos_min=j;
		temp=arr[pos_min];	
		} //end if
		
	arr[pos_min] = arr[i];
	arr[i] = temp;
	} //end for (i)
}  //end selectionSort

int binarySearch(int lo, int hi, char key[], WORDS list[]) {	//Function to search for word and return location.
//search for key from list[lo] to list[hi]
//if found, return its location; otherwise, return -1
while (lo <= hi) {
int mid = (lo + hi) / 2;
int cmp = strcmp(key, list[mid].Word);
if (cmp == 0) return mid; // found
if (cmp < 0) hi = mid - 1;
else lo = mid + 1;
}
return -1; //lo and hi have crossed; key not found
} //end binarySearch

int LoadData(WORDS word[]){										//Function to load all data into struct array word..
	ifstream input;	
	input.open("Input.txt");

//                                     FILE MISSING				
//-------------------------------------------------------------------------------------------------------
 if(!input.is_open()){
cout<<endl<<endl<<endl<<" \tHey !! The file 'Input.txt' is either missing or Broken."<<endl;
system("Exit");
}

//-------------------------------------------------------------------------------------------------------
//                             Assigning to ARRAY	
//------------------------------------------------------------------------------------------------------	
	
	//DECLARATION OF VARIABLES 
	string dummy;
	int c= 0;
	int i= 0;
	int word_amt;
	char dumWord[25];               							//array to hold word temporarily
	
	input>>dummy;												//read in first word

	while(!(dummy=="@@@@@")&&i<100){							// stopping condition for input file							

	strcpy(dumWord,dummy.c_str()); //this was found via google.copy the string dummy into the temporary array dumWord. 
	word_amt=dummy.length();       // built in functions from string.h..this gives lenght of temp word and assign it to
								   // to the int word_amt.
		for(int y=0;y<word_amt;y++){				                          // THIS IS IMPORTANT 
	dumWord[y]=toupper(dumWord[y]);										  // UPPERCASE ALL LETTERS IN ORDER TO SORT CORRECTLY
	}
	if (isWord(dumWord,word_amt)&&binarySearch(0, i, dumWord, word)<0){ //checks whether dord is word and search struct word for it
		word[i].Amt=dummy.length();                                      // if it's not their then it assign the temp word to the array struct
		strcpy(word[i].Word,dumWord);									 //now using string copy funct we copy temp word to array struct
												 // then we sort what's in the array
	i++;	selectionSort(word,i);	
	}
	input>>dummy;														 //read in another temp word
	c++;
	
	if(c<5){
		Sleep(100);
		cout<<". ";
	}
	
}

input.close(); //close file
return i; // return amount of words in array
}
	
void separatOr(char p,int a){ 							//name says it all but not { necessary at all } this for menu

	for (int i=1;i<=a;i++){
		cout<<p;
	}	
	cout<<endl;
}

void PrintWord(WORDS data[],int amt){                  //this function is to print words when option 2 selected in menu
system("cls");										   //		N O T   N E C E S S A R Y
cout<<"\n\n\t  L O A D E D  -  W O R D S\n\n";

cout<<"\t************************************\n";
int count =0;int r=0;
int m = 1; 
int p = 1; //p is column
while(r<amt){
cout<<"  "<<r+1<<".\t*\t";

	for	(int j=r;j<p*m;j++){
		for (int i=0 ; i<data[j].Amt;i++){
			cout<<data[j].Word[i];	
		}//cout<<"\t*";		 
   }cout<<endl;
   
 m++;r+=p;
	}
cout<<"\t************************************\n";	
}


//******************************************************************************************
//						L O A D   G R A P H I C
//******************************************************************************************
struct characters{                    				//Not Explaining this graphic part
	char letter[150];				  				// what it does, read the information in the Graphic.txt file and store them in array
	int Amt;
};
struct GRAPHIC {
	characters Line[150];			   				// NB this is how you do nested struct and array
	int WrongGuess;					 			    // 
	};                                 				//                 
	
void print_Graphic(GRAPHIC graph[],int wrongguess){ // this function is to print the 1-D graphic (man hanging)
	int i=0,j=0,p=0;

	i = wrongguess-1;
 	while(j<8){
 		while(p<graph[i].Line[j].Amt){		
		 	cout<<graph[i].Line[j].letter[p];			
 		p++;
 			
		 }
		 p=0;
		 cout<<endl;
	    j++;    
        }
        j=0;
}

int loadGraphic(GRAPHIC graph[]){					//function to load graphic file and store it in nested struct arry
ifstream input;	
	input.open("Graphics.txt");
//                                     FILE MISSING				
//-------------------------------------------------------------------------------------------------------
 if(!input.is_open()){
cout<<endl<<endl<<endl<<" \tHey !! The file 'Graphic.txt' is either missing or Broken."<<endl;
system("Exit");
}

//-------------------------------------------------------------------------------------------------------
//                             Assigning to ARRAY	
//------------------------------------------------------------------------------------------------------	
	//DECLARATION OF VARIABLES
	char s[150];	
	string line;
	int i=0;
	int guess;
	int j=0;
	char ch;
	int k=0;
while(!input.eof()){

	input>>noskipws>>guess;
	graph[i].WrongGuess=guess;
	
 	while(j<8){
 	
 	while(input>>noskipws>>ch&&ch!='\n'){ 		  //read in lines by lines and store each character of each line in arrays
 		graph[i].Line[j].letter[k]=ch;
 		
	k++;
	 } graph[i].Line[j].letter[k]='\n';
	      
       	 graph[i].Line[j].Amt=k;
       	 
		k=0;	
		j++;      
        }
        j=0;
		i++;
		
		
		if(i<5){
		Sleep(100);
		cout<<". ";
	}
//cout<<graph[i].WrongGuess<<endl;
}
	   return i;	   	
}


//******************************************************************************************
//						  G A M E  -  S I M U L A T I O N
//******************************************************************************************

int n = 0;       				//not necessary but needed something to store the hidden word. you can accompensate for this during coding
struct SECRET{ 					// struct to store letters of hidden word
	char Letter;
	bool Hidden;
	bool Played; 				//not needed really
	
};
struct SECRETWORD{ 				//same as the graphic part.. this is nested struct with array..
	SECRET word[25];
	bool Shown;
	int AMT;
};

//*********************************************
void MESSAGES(int opt,char character){   //inconclusive

if (opt == 1){
cout<<"\t\tOops, "<<character<<" was played already!\n";	
}	else 
if(opt == 2){
	cout<<"\t\tNOOO! "<<character<<" was Wrong!\n";
	
}else 
if(opt == 3){
	cout<<"\t\tHEY!!, That "<<character<<" is not a letter! (- _ -)\n";	
}
}
//**************************************************************
//					PLAYED LETTERS
//**************************************************************

struct Alphabet{           											// this section is wholeheartedly not necessary
	char Letter;		   											// All it does is show the played letters that you entered in each runtime
	bool played;
	int time;
};
void initializer (Alphabet alpha[]){    							// initialize all array with letters 
	int k = 0;
	for (int i=0;i<26;i++){
		alpha[i].Letter=toupper('a'+i); 							// captitalized each letter
		alpha[i].played=false;										// because it will be easy for both display and search 'a' and 'A' both have different ascii codes
		alpha[i].time = 0;
	}
}
bool Set_Guess(int lo,int hi,Alphabet arr[],char guess){ 			//function search and set the guess character in the array
//search for key from list[lo] to list[hi]
//if found, return its location; otherwise, return -1
bool Played=false;
bool complete=false;
int i , k = hi;
//	int i = Location(guess,arr,x);
//	cout<<i<<endl;
while (lo <= hi&&!complete) {
int mid = (lo + hi) / 2;
if (arr[mid].Letter==guess){
if (arr[mid].played)	{
Played=true;}else {	

arr[mid].played=true;

if(i==k)complete=true;
}

 } // found
 if (guess<arr[mid].Letter) hi = mid - 1;
else lo = mid + 1;
i++;
}
return Played;
 //lo and hi have crossed; key not found
 //end binarySearch
}

void show_PlayedLetter(Alphabet alpha[],int amt){  //function to show the user all the letters that are played
													//it runs through the array and then if condition true it prints it to command prompt

for (int i=0;i<amt;i++){
	if (alpha[i].played){		
		cout<<alpha[i].Letter<<" ";
		
		}					
			}			
		}	
//**************************************************************
//					SECRET LETTERS
//**************************************************************
	//this section deals with the hidden word

SECRETWORD initializer ( WORDS data[],int t){    	//  a function that's a struct... this func initialise
	SECRETWORD alpha;								//  it sets the word from the struct array that was loaded previous and 
	int i = 0;										//  assign it to the secretword struct with array 1;
	for (i=0;i<strlen(data[t].Word);i++){			//  this part you can fix and put it as a single var.. i did array
	alpha.word[i].Letter=toupper(data[t].Word[i]);	//  to save me the trouble because from the start i didnt compensate
	alpha.word[i].Hidden=true;						//  the carrying forward of the struct
	alpha.Shown=false;								//  when coding yours just make sure you keep in mind of this hidden struct
	alpha.word[i].Played=false;						//  you can also not use struct to do these things and just use array
	alpha.AMT=data[t].Amt;							//  where you kept searching the hidden word array for the words and if found then print else print *
		}											//  there are many ways to do it. Use the way that you can get it done quick and easy
	alpha.word[i+1].Letter='\0';
	alpha.word[i+1].Hidden=false;
//	alpha.AMT+=1;	                                // i did not increment the amount of word as it is more convenient to me to not to
		return alpha;								// because when printing out i wont have to figure out how much to print out as always
													// you can use the '\0' as an advantage also when printing out data
}

bool CheckWin(SECRETWORD alph[]){                   // This function checks whether all the letters in the hidden struct is false and it
	for (int i = 0; i < alph[0].AMT; i++)			// will then return true if wins. but if 1 letter is hidden then false will it return
	{
		if (alph[n].word[i].Hidden){
			return false;
		}
	}
	return true;	
}
struct CONDITIONAL {                                 // This struct is place here because i needed to create a message for when a letter is 
	bool win;	  									 //  already played and one if the correct letter is pressed	
	bool correct_word;
};
CONDITIONAL SecretWordSearch(int lo, int hi, char g, SECRETWORD alph[]){ //function to return 2 boolean variables 
CONDITIONAL played;														 //dummy CONDITIONAL var
 for (int i = 0; i < alph[0].AMT; i++)
	{	
		if (alph[n].word[i].Letter==g){									 //search hidden struct array for the character g (guess)
		if(!alph[n].word[i].Hidden&&alph[n].word[i].Played)	{			 // if found it then check to see if it's hidden and played already
			MESSAGES(1,g);												 // message should be placed here but it's
		}			
		else{															 // with the else part. this here knows the word isnt played and then 
			alph[n].word[i].Hidden = false;								 // it sets the letter as played and hidden as false .: revealing the letter
			alph[n].word[i].Played=true;								 // then sets the played.correct word as true
			played.correct_word = true;
		   } 
		}
	}
	played.win=CheckWin(alph);                                           // checks whether the game is win using this function and assign it to the other bool of the struct CONDITIONAL
	return played;														 // returns the struct played
} //end binarySearch
	

int GUESS(char guess,SECRETWORD alpha[],int MAXGUESS,Alphabet abet[]){   // this function is where almost everything happens
																		 // it calls the previous functions and sends the amount of guesses remaining base on it's logical conditioning
bool correct,win,replayed;												 // it checks whether all conditions and call the assigning function Secretwordsearch and set guess.
																		 
CONDITIONAL x =SecretWordSearch(0, alpha[n].AMT,guess,alpha );			 // the struct x takes all the boolean from SecretWordSearch and holds it, 
																		 //	this was done like this so that calling the function twice is not necessary.
replayed      =Set_Guess(0,25,abet,guess);                               // this is to show played letter.   
	
if(x.correct_word||x.win||replayed||!isLetter(guess)){                   // conditioning if statement checks whether the game was won,a correct letter was played, if the guess character
																		 // was played twice and if it's not a letter.
	cout<<"why am i not seeing here"<<endl;
	return MAXGUESS;													 // if above statemnts were true, any one it would then return the same MAXGUESS it came in with
}else{	//try again														
	 return MAXGUESS-1;													 // else return 1 guesses less
} 

	 }
	
void show_RLetter(SECRETWORD x[]){                                       // function reveals the letters that are not hidden and displays 
																		 // an asterisk as the letters that are hidden
cout<<"\t\t";
for (int i=0;i<x[n].AMT;i++){
	if (!x[n].word[i].Hidden&&x[n].word[i].Letter!='\0'){				
	cout<<" "<< x[n].word[i].Letter<<" ";		
		}	
		else cout<<" * ";						
		}
	}
		
int random(int m, int b) {												 // function randomise the numbers between m and n 
	//srand(time(0));														 // randomise the words in array struct data[]
//returns a random integer from m to n, inclusive
int offset = rand()%(b-m )+1;
return m + offset;

} //end random

int RestartGame(GRAPHIC graph[],WORDS data[],int amt,int g);              // this function is a bit flawed
																		  // it suppose to restart the game everything but it's flawed when 
																		  // you return to menu and press 3 to exit... that won't be 
																		  // anything bad to affect marks as it was just a little over the 
																		  // requirements.


//**************************************************************
//					GAME PLAY
//**************************************************************


void Display(GRAPHIC graph[],WORDS data[],int amt,int g){    		// this function wholes the entire hang man game in it
int MAXGUESS = 8;													// # of plays a user has.	
int i = 1;															// to keep track of guesses
char guess;															// character from keyboard

Alphabet abet[26];													// Holds the entire alphabet
SECRETWORD alpha[n];												// Holds the hidden word

int r = random( 0,amt);												// Generates a random number from 0 to amt


alpha[n] = initializer (data,r);									// the hidden word array takes the word that generates from initializer which came from the data struct array that was loaded at in the beginning
 initializer (abet);												// Sets the letters in the alphabet to not play = false



system("cls");

while(guess!='.'){													// runs game until win/lost or '.' to stop
	
	cout<<"\n\n   -------------------------------------------------------------------------"<<endl;
	setColor(22);cout<<      "\t  W E L C O M E  T O  T H E  G A M E  O F  H A N G M A N  \n";setColor(7);
	cout<<    "   -------------------------------------------------------------------------"<<endl;
	cout<<"\n\n\tREMAINING GUESSES : "; 
	setColor(22);cout<<"  "<<MAXGUESS<<"  "<<endl;setColor(7);	// #number of guesses
	
	cout<<"\n\t\t";
	
	
	if(MAXGUESS<1&&!CheckWin(alpha)){								// Checks if game win and print required words
   	//system("cls");
   	print_Graphic(graph,9);											// prints graphic that was obtained from Graphic.txt
   	cout<<"\n\n\t G A M E  O V E R   !! "<<endl;
   		cout<<"\n\n\t The word was : ";
	for (int i=0;i<alpha[n].AMT;i++){	
	cout<<" "<< alpha[n].word[i].Letter<<" ";						// prints out entire hidden word
		
		}	
	
		   cout<<"\n\n\n\t\t < B E T T E R  L U C K  N E X T  T I M E >";
		   cout<<"\n\n\n\tPress any key to return to MENU...\n\n";
		   getch();//	RestartGame(graph,data,amt,g);               // restarts the game but is  flawed, you can use this if want to restart but fix flaw, uncomment the function RestartGame and comment break;
		   			break;									         // this breaks and go to menu
   }else if(CheckWin(alpha)) {										 // this if statement checks for win game.. if win
   		print_Graphic(graph,10);									 // it will then print the words and a congrats message...

   	cout<<"\n\n\t W I N   !! "<<endl;
   		cout<<"\n\n\t The word was : ";
	for (int i=0;i<alpha[n].AMT;i++){	
	cout<<" "<< alpha[n].word[i].Letter<<" ";
		
		}	
		   cout<<"\n\n\n\t\t < C O N G R A T U L A T I O N S !! Y O U  W O N !! >";
		   cout<<"\n\n\n\tPress any key to return to MENU...\n\n";
		   getch();	
		  // RestartGame( graph,data,amt,g);
		   break;   		
   }
    setColor(i);
	print_Graphic(graph,i);											 // prints the graphics from the array struct graphic ie the man getting hang every incorrect guesses
	setColor(7);
	cout<<"\n\n\tHIDDEN WORD : ";	//show_RLetter(x,9);
	    setColor(5);
			show_RLetter(alpha);									 // shows the letters that are played and asterisks as those that havent played yet
		setColor(7);
	cout<<"\n";
	
	/*
	 	----------------------
	 		How game works
	 	----------------------
	 	
	 	we make our guess, send guess to function to reveal it from word. using alphabet we place all 
	 	letters of word in false boolean
	
	
	*/
			
	cout<<"\n   -------------------------------------------------------------------------"<<endl;
	setColor(3);
	cout<<"\t\t\tL E T T E R  P A N E L\n";
	setColor(7);
	
	
	cout<<"   -------------------------------------------------------------------------"<<endl;
	setColor(6);
	cout<<"\n\t\t"; show_PlayedLetter(abet,26);							// shows the letters that were already pressed in alphabetical order.
																		// this can change to order u typed it in just use the struct branch time and sort by lowest with the exception of zero
	setColor(7)		;															
	cout<<"\n   -------------------------------------------------------------------------"<<endl;
	
//	cout<<"\t\t\tE R R O R  P A N E L\n";
//	cout<<"   -------------------------------------------------------------------------"<<endl;

//	MESSAGES(p[0].opt,p[0].Character);
//	this function will be using global variables to keep track and keep the message in position
	

   guess=toupper(getch());												// gets and converts the key entered to capital letter .. u can use -32 if you dont wwant to use the function to upper. 
   MAXGUESS=GUESS(guess,alpha,MAXGUESS,abet);							// well this takes guess and does all the requirements in the game ( MAIN PART )
 
 
  if(MAXGUESS<9-i){														 // here is needed to keep record of the graphics. if maxguess is less than 9 - amount of guesses gone then it will add another to i
  	i++;
  } 
  system("cls"); 
	}	
}
//******************************************************************************************
//				P R O G R A M  B A C K B O N E
//******************************************************************************************
void menu(GRAPHIC graph[]){                                              // just the main menu..
	cout<<  "\n";
	setColor(14);
	print_Graphic(graph,11);
	setColor(7);
	cout<<  "\n\n\t";separatOr('=',60);
	cout << "\t %";cout<<"\t\t   H  A  N  G  M  A  N  \t\t";cout<<"%" << endl;
	cout<<  "\t %------------------------------------------------------%"<<endl;
	cout << "\t %  Select an option\t\t\t\t\t% " << endl;
	
	cout << "\t %\t\t\t\t\t\t\t% " << endl;
	cout << "\t %  \t1. S T A R T  G A M E\t\t\t\t% " << endl;
	cout << "\t %  \t2. Show Loaded Words\t\t\t\t% " << endl;
	cout << "\t %  \t3. Show REPORT FILE \t\t\t\t% " << endl;
	cout << "\t %  \t4. Exit\t\t\t\t\t\t% " << endl;
	cout << "\t %\t\t\t\t\t\t\t% " << endl;
    cout<<  "\t";separatOr('%',60);
    
}



int main(){
	srand(time(0));														// required for the randomizing because for every run of program this will change and not be same entirely..
//--------------------------- MENU --------------------------------
WORDS data[100];														// saves the loaded words into this struct array
GRAPHIC graph[20];		
cout<<"\n\tLoading Words ";												// saves the loaded graphic images (characters) into graphic struct array
int amt = LoadData(data);												// initializes and collects the amount of words in the data struct array
system("cls");
cout<<"\n\tLoading Graphics ";	
int   g = loadGraphic(graph);											// initializes and collects the amount of graphics in the data struct array
system("cls");

//for(int i=0;i<50;i++){
//setColor(i);
//cout<<" Color : "<<i<<endl;	setColor(7);
//}

char choice;
	
// OPTION MENU



while (choice!=53){	

cout<<endl<<endl;
//
menu(graph);															// calls menu function and prints it at the start of program
	
// get the response	
choice=getch();  														// gets menu options
cout<<endl<<endl;

//----------------------------------------------------------------------
//						OPTION 1
//----------------------------------------------------------------------
if(choice==49){ // character 1 in dec is 49
 Display(graph,data,amt,g);
}
//----------------------------------------------------------------------
//						OPTION 2
//----------------------------------------------------------------------
else if (choice==50){ //PART 2
PrintWord(data, amt);
getch();
system("cls");return main();

}
//----------------------------------------------------------------------
//						OPTION 3
//----------------------------------------------------------------------
else if (choice==51){ //PART 3

system("explorer.exe REPORT.pdf");

}
//----------------------------------------------------------------------
//						OPTION 4
//----------------------------------------------------------------------
else if (choice==52){
	return 0;
}
//----------------------------------------------------------------------
//					IF OTHER KEYS ARE PRESSED
//----------------------------------------------------------------------
else		{
	cout<<"\t\tPlease choose OPTION !"<<endl;
	system("cls");
			}
system("cls");
		}
}

int RestartGame(GRAPHIC graph[],WORDS data[],int amt,int g){   			// a bit flawed.. needs to reset the entire arrays etc;
	system("cls");
	cout<<"\n\n\tDo you want to play again? y/n ";
	char playagain=toupper(getch());
if(playagain=='Y'){
Display(graph,data,amt,g);	  
}else{
	system("cls");
	return main(); 														//NUMBERS NOT WORKING BECAUSE OF ISLETTER() to take menu opt after game
} 
}
