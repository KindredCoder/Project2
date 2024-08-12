/*
*   Produced by Kyle Gibson
*   SC210 - Project 2
*   Date Created 8 Aug 2024
*   AIRGEAD BANKING APPLICATION
*/

#include <iostream>
#include "BankReport.h"
#include <iomanip> //I used this to formatt my menu
#include <string>

using namespace std;

//Declarations
void printStars(int width); //Used to add in "*" line to seperate data like in the project example

int main() {
    int width = 60;
    printStars(width);
    cout << setw(24) << "" << "User Input" << endl;
    printStars(width);

    cout << left;
    cout << setw(27) << "Initial Investment Amount" << ": $";  //setw(27) formatt to always keep input in line
    double initialAmount;
    cin >> initialAmount;

    cout << setw(27) << "Monthly Deposit" << ": $";
    double deposit;
    cin >> deposit;

    cout << setw(27) << "Annual Interest" << ": %";
    double annualInterest;
    cin >> annualInterest;

    cout << setw(27) << "Number of Years" << ": ";
    int durationOfAction;
    cin >> durationOfAction;

    BankReport report(initialAmount, deposit, annualInterest, durationOfAction);

    anyKey();

    //BankReport report;  //Used for testing

    report.printReports();


    //userModifyMenu();
    int userSelection = 0;
    cout << "Would you like to modify your original Inputs?" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cin >> userSelection;

    while (userSelection != 2) {

        if (userSelection == 1) {
            int width = 80;
            int userChoice = 0;
            printStars(width);
            cout << "Choose from these Options!" << endl;
            cout << "1) Modify Initial Deposit of $" << report.getInitialAmount() << endl;
            cout << "2) Modify Monthly Deposit of $" << report.getDeposit() << endl;
            cout << "3) Modify Annual Interest Rate %" << report.getAnnualInterest() << endl;
            cout << "4) Modify The Amount of Years " << report.getDurationOfAction() << endl;
            cout << "5) To Quit!" << endl;
            printStars(width);            
            cin >> userChoice;
            

            switch(userChoice) {
                case 1: {
                cout << "Modify Initial Amount $" << report.getInitialAmount() << " : $";
                double newInitialAmount = 0;
                cin >> newInitialAmount;
                report.setInitialAmount(newInitialAmount);
                report.printReports();
                break;
                }

                case 2: {
                cout << "Modify Month Deposit Amount $" << report.getDeposit() << " : $";
                double newDeposit = 0;
                cin >> newDeposit;
                report.setDeposit(newDeposit);
                report.printReports();
                break;
                }

                case 3: {
                cout << "Modify Annual Interest %" << report.getDurationOfAction() << " : %";
                double newAnnualInterest = 0;
                cin >> newAnnualInterest;
                report.setAnnualInterest(newAnnualInterest);
                report.printReports();
                break;
                }

                case 4: {
                cout << "Modify " << report.getDurationOfAction() << " Years: ";
                int newYears = 0;
                cin >> newYears;
                report.setDurationOfAction(newYears);
                report.printReports();
                break;
                }

                case 5: {
                    cout << "Ending Program..." << endl;
                    return 0;
                }

                default:
                    cout << "Invalid Option!" << endl;
                break;

            }
        }
    }

    return 0;

}

void printStars(int width) {
    string line(width, '*');
    cout << line << endl;
}

