/*
	Author: Daniel Arredondo
	Date: January 5th, 2026
	Purpose: C++ Template
*/

//System Libraries
#include <iostream>//Input/Output Library
#include <cstdlib> //Random Number Library
#include <ctime>   //Time Library
#include <fsteam>
#include <string>
using namespace std;

//User Libraries

//global Constants - Physics/Chemistry/Conversions/Arrary Dimensions

//Function Prototypes
	int menu();
//Execution Begins Here
int main (int argv,char **argc) {
    //Set the Random Number Seed
	srand(static_cast<unsigned int>(time(0)));
	//Declare Variables  
	int belly = 0;
    int poplim = 0;
    int choice = 0;
    bool play = true;
    bool pturn = true;
    string key;
	//Intialize Variables
	//menu screen
	cout << "pop the pig game\n"
	
	//mapping process -> Input to Outputs
	//Display Input/Outputs
	//Game loop
	return 0;
};	
	// menu
	int menu() {
    int m;
    cout << "\n1. Start Game\n";
    cout << "2. Quit\n";
    cout << "Enter choice: ";
    cin >> m;
    return m;
}
