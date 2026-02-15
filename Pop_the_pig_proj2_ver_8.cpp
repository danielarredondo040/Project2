/*
	Author: Daniel Arredondo
	Date: January 5th, 2026
	Purpose: C++ Template
*/

//System Libraries
#include <iostream>//Input/Output Library
#include <cstdlib> //Random Number Library
#include <ctime>   //Time Library
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//global Constants - Physics/Chemistry/Conversions/Arrary Dimensions

//Function Prototypes
int menu();
int roll (int max);
void plyTurn(int &belly)
void cpuTurn(int &belly)
bool chkPop (int belly, int poplim);
void logGame(int belly,int poplim);
void sortLos (int los[], string name[], int size);
void showArr (string name[], los[], size);
int findPly(string name[], int size, string key);
int sumLos (int los[], int size);
int maxLos (int los[], int size);
int minLos (int los[], int size);
void saveDat (string name[], int los[], int size);
int roll(int max);
int roll();
void initArr (int los[],int size);
void logGame (int belly, int poplim, string loser);
void banner ();
void rules ();
void pause();
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
	// file save
	saveDat(name, los, SIZE);

    cout << "\nGames played this session: " << games << endl;
    cout << "Results saved to output files.\n";
	return 0;
}
	// menu
	int menu() {
    int m;
    cout << "\n1. Start Game\n";
    cout << "2. Quit\n";
    cout << "Enter choice: ";
    cin >> m;
    return m;
	}
	// dice
	int roll() {
    return rand() % 3 + 1;
	}

	int roll(int max) {
    return rand() % max;
	}
	//validation
	bool valid(int val, int low, int high) {
    return val >= low && val <= high;
	}
	// game logic
	bool chkPop(int belly, int poplim) {
    return belly >= poplim;
	}

	void plyTurn(int &belly) {
    int die = roll();
    int feed = 0;

    cout << "\nPlayer Turn\n";

    switch (die) {
        case 1:
            feed = 1;
            cout << "Red hamburger (+1)\n";
            break;
        case 2:
            feed = 2;
            cout << "Yellow hamburger (+2)\n";
            break;
        default:
            feed = 3;
            cout << "Green hamburger (+3)\n";
    }

    belly += feed;
    cout << "Belly size: " << belly << endl;
	}

	void cpuTurn(int &belly) {
    int die = roll();
    int feed = die;

    cout << "\nComputer Turn\n";
    cout << "Computer feeds +" << feed << endl;

    belly += feed;
    cout << "Belly size: " << belly << endl;
	}
	// array utils
	void initArr(int los[], int size) {
    for (int i=0;i<size;i++) {
        los[i] = 0;
    }
	}

	void showArr(string name[], int los[], int size) {
    cout << left << setw(10) << "Name" << "Losses\n";
    cout << "-----------------\n";
    for (int i=0;i<size;i++) {
        cout << left << setw(10) << name[i] << los[i] << endl;
    }
	}

	void sortLos(int los[], string name[], int size) {
    for (int i=0;i<size-1;i++) {
        for (int j=0;j<size-1;j++) {
            if (los[j] > los[j+1]) {
                int tmp = los[j];
                los[j] = los[j+1];
                los[j+1] = tmp;

                string t = name[j];
                name[j] = name[j+1];
                name[j+1] = t;
            }
        }
    }
	}

	int findPly(string name[], int size, string key) {
    for (int i=0;i<size;i++) {
        if (name[i] == key) {
            return i;
        }
    }
    return -1;
	}
	//stats 
	int sumLos(int los[], int size) {
    int sum = 0;
    for (int i=0;i<size;i++) {
        sum += los[i];
    }
    return sum;
	}

	int maxLos(int los[], int size) {
    int max = los[0];
    for (int i=1;i<size;i++) {
        if (los[i] > max) {
            max = los[i];
        }
    }
    return max;
	}

	int minLos(int los[], int size) {
    int min = los[0];
    for (int i=1;i<size;i++) {
        if (los[i] < min) {
            min = los[i];
        }
    }
    return min;
	}
	// file
	void saveDat(string name[], int los[], int size) {
    ofstream out("pig_proj2.txt");
    for (int i=0;i<size;i++) {
        out << name[i] << " " << los[i] << endl;
    }
    out.close();
	}
	void logGame(int belly, int poplim, string loser) {
    ofstream out("pig_log.txt", ios::app);
    out << "Final belly: " << belly << endl;
    out << "Pop limit: " << poplim << endl;
    out << "Loser: " << loser << endl;
    out << "------------------\n";
    out.close();
	}
	//Output Functions
	void banner() {
    cout << "   POP THE PIG GAME\n";
	}
	void rules() {
    cout << "\nRules:\n";
    cout << "1. Take turns feeding the pig.\n";
    cout << "2. Each turn adds 1-3 belly size.\n";
    cout << "3. If the pig pops, you lose.\n";
	}
	void pause() {
    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
	}