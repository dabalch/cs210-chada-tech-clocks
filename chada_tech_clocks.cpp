/**************************************************************
*  Name: Dawit Balcha
*  Project: Chada Tech Clocks
*  Purpose: Display dual clocks (12-hour and 24-hour) with
*           user options to update time.
**************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// formatTime12 function with standard AM/PM
string formatTime12(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    unsigned int displayHour = hours % 12;
    if (displayHour == 0) displayHour = 12;
    string period = (hours < 12) ? "AM" : "PM";

    stringstream ss;
    ss << setfill('0') << setw(2) << displayHour << ":"
        << setw(2) << minutes << ":"
        << setw(2) << seconds << " " << period;

    return ss.str();
}

// Class to represent and handle time for both clocks
class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock() : hours(0), minutes(0), seconds(0) {}

    void addHour() {
        hours = (hours + 1) % 24;
    }

    void addMinute() {
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            addHour();
        }
    }

    void addSecond() {
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            addMinute();
        }
    }

    void display12Hour() {
        string time12 = formatTime12(hours, minutes, seconds);
        cout << "*     " << time12 << "     *";
    }

    void display24Hour() {
        cout << "*     " << setfill('0') << setw(2) << hours << ":"
            << setw(2) << minutes << ":" << setw(2) << seconds << "         *";
    }
};

//  Display both clocks side by side on one line
void displayClocks(const Clock& clock) {
    cout << "\n*************************    *************************" << endl;
    cout << "*     12-Hour Clock     *    *     24-Hour Clock     *" << endl;
    cout << " ";
    clock.display12Hour();
    cout << "    ";
    clock.display24Hour();
    cout << endl << "*************************    *************************" << endl;
}

// Function to display the user menu
void displayMenu() {
    cout << "\n*************************" << endl;
    cout << "* 1 - Add One Hour      *" << endl;
    cout << "* 2 - Add One Minute    *" << endl;
    cout << "* 3 - Add One Second    *" << endl;
    cout << "* 4 - Exit Program      *" << endl;
    cout << "*************************\n" << endl;
}

int main() {
    Clock myClock;
    int choice;

    do {
        displayClocks(myClock);
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number from 1 to 4: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            myClock.addHour();
            break;
        case 2:
            myClock.addMinute();
            break;
        case 3:
            myClock.addSecond();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
