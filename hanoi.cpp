// Dustin Gordon


#include <iostream>

using namespace std;

int steps = 0;

void moveTower(int disks, char source, char dest, char spare)
{
    if(disks == 0) //Case for single disk
    {
        cout << "Moved disk " << disks << " from rod " << source << " to rod " << dest << "." << endl;
        steps++;
        return;
    }
    else
    {
        //Recursively call parent function to sort towers:
        moveTower(disks-1, source, spare, dest);
        steps++;

        //Print sorting progression to console:
        cout << "Moved disk " << disks << " from rod " << source << " to rod " << dest << "." << endl;

        //Reverse destination and source pegs:
        moveTower(disks-1, spare, dest, source);
    }
}

int main() 
{
    cout << endl;
    cout << " ______________________  HANOI TOWER SOLVER  _______________________" << endl;
	cout << "*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*" << endl;
	cout << "*\t\t (Recall that n initial disks would be called as:\t\t\t*" << endl;
	cout << "*\t\t\t  disk 0, disk 1, disk 2, ..., disk n-1\t\t\t\t\t*" << endl;
	cout << "*\t\t  ...and we want to move all of them to peg B).\t\t\t\t*" << endl;
    cout << "*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*" << endl;
    cout << "* ----------------------------------------------------------------- *" << endl;
    cout << "   Please enter the number of disks initially on peg A to continue: " << endl;
    cout << "\n-->";

	int input;
	bool valid = false;

	while(valid == false) //User input validation
    {
        cin >> input;
        if(input <= 0)
        {
            cout << "\nERROR! Number of disks must be greater than zero." << endl;
            cout << "\n   Please enter the number of disks initially on peg A to continue: " << endl;
            cout << "\n-->";
        }
        else
        {
            valid = true;
        }
    }

	moveTower(input-1, 'A', 'B', 'C');

	//Summarize results:
	if(steps == 1)
	{
        cout << "\n*Done! Hanoi Tower of " << input << " disk sorted in " << steps << " move.\n";

    }
    else
    {
        cout << "\n*Done! Hanoi Tower of " << input << " disks sorted in " << steps << " moves.\n";

    }

	return 0;
}

