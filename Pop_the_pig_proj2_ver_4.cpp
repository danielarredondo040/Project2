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
int roll (int max);
void plyTurn(int belly)
void cpuTurn(int belly)
bool chkPop (int belly, int poplim);
void logGame(int belly,int poplim);
void sortLos (int los, string name[], int size);
void showArr (name, los, size);
int findPly(string name[], int size, string key);
int sumLos (int los[], int size);
int maxLos (int los[], int size);
int minLos (int los[], int size);
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
	//arays
	string name[SIZE] = {"Daniel","Alex","Sam","Jess","Ryan"};
    int los[SIZE];
	//Intialize Arrays
	initArr(los, SIZE);
	//Display title and rules
	banner();
    rules();
	//menu screen
	 choice = menu();

    if (!valid(choice,1,2)) {
        cout << "Invalid menu choice.\n";
        exit(0);
    }

    if (choice == 2) {
        cout << "Goodbye!\n";
        exit(0);
    }
	//pop limit
	poplim = roll(11) + 20;
	games ++;
	//Game loop
	while (play) {

    if (pturn) {

    plyTurn(belly);

    if (chkPop(belly, poplim)) {
    cout << "\nPOP! You popped the pig!\n";
	los[0]++;
	logGame(belly, poplim, "Player");
	play = false;
	} else {
	pturn = false;
	}

	} else {

	cpuTurn(belly);

	if (chkPop(belly, poplim)) {
	cout << "\nPOP! Computer popped the pig!\n";
	logGame(belly, poplim, "Computer");
	play = false;
	} else {
	pturn = true;
	}
	}
    }
    pause();
	// stats
	 cout << "\n--- Player Statistics ---\n";
    showArr(name, los, SIZE);

    cout << "\nSorting players by losses...\n";
    sortLos(los, name, SIZE);
    showArr(name, los, SIZE);

    cout << "\nEnter player name to search: ";
    cin >> key;

    int pos = findPly(name, SIZE, key);

    if (pos != -1) {
        cout << name[pos] << " losses: " << los[pos] << endl;
    } else {
        cout << "Player not found.\n";
    }

    cout << "\nTotal losses: " << sumLos(los, SIZE) << endl;
    cout << "Max losses: " << maxLos(los, SIZE) << endl;
    cout << "Min losses: " << minLos(los, SIZE) << endl;
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
