//File Creator App
//Functions: Creates and writes to file, and reads created file
//Created By: D'Angelo Walker
//Version: 1.0

//Standard libraries included as well as file libraries
#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>


using namespace std; 

void Write2File(string arg1); //Declared prototype for file creator function
void ReadFile(string arg); //Declared prototype for file reader function

int main()
{
    system("cls"); //clear screen used for a tidy GUI
   int option; //This variable is used to validate the user's menu selection
   string filename; //The file name is declared as a string

//Main Menu
   printf("\t\t\tWelcome to our 'File Editor' (Please choose your option 1 or 2 from the menu below)\n");
   printf("\n 1. Write to File\n 2. Read from file\n\n");
   scanf("%d", &option); //User enters 1 to create a file or 2 to read from the created file
   if (option == 1) {
      printf("\n\n Your option is %d\n\n", option);
      system("pause");
      system("cls");
      printf("\t\t\t\t\t*******File Editor*******\n");
      printf("\nEnter the name you want to give your file ... \t");
      cin >> filename; //file name stored
      
      Write2File(filename); //Function triggered to create file
   }
   else if(option == 2) {
       ReadFile(filename);//Function to read text placed in written file
   }else{
       printf("Your option is not available! \n\n SESSION TERMINATED!!!!"); //Message shown if input is invalid
   }
   return EXIT_SUCCESS; //App exits here
}

void Write2File(string fname) {
    int choice;

    ofstream NewFile(fname); //New file created here with the name the user stored
    NewFile << "This is a test file"; //Text written to newly created file
    NewFile.close(); //File should be closed when created
    printf("\n\nYour file was created successfully!!\n\n");
    system("pause");
    system("cls");
    printf("\t\t\t\t\t*******File Editor*******\n");
     printf("\nDo you wish to return to the main menu ? \n\n1.Yes\n2.No\n\n");
    cin >> choice; //Validates user's option to return to menu or exit app

   switch(choice){
       case 1:
       main();
       break;

       case 2:
       exit;
       break;

       default:

       cout << "Your option is not available! \n\n SESSION TERMINATED!!!!\n\n";
   } 


}

void ReadFile(string fname) {
    string Reading; //Variable to store file's text in a string

    ifstream Ready2Read(fname+".txt"); //Targets the created file
    while (getline(Ready2Read, Reading)) { //Each line in the file is stored in the "Reading" variable and printed out to the screen 
        cout << Reading;
    }
    Ready2Read.close(); //File is closed when no longer in use
    printf("\n\n\n");
    system("pause");
    exit; //Exits app
  
}