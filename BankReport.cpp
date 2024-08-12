#include "BankReport.h"
#include <iostream>
#include <iomanip> // formatting and setprecision for outputs

using namespace std;

void printTableHeadWithout(int width); // without Deposits
void printTableHeadWith(int width); // With Deposits

void anyKey() {
    cout << setw(20) << "Press any key to continue…" << endl;
    cin.ignore();
    cin.get();
}

//Default Constructor
BankReport::BankReport(){ //I used this at the beginning to test multiple areas
    initialAmount = 1.0;
    deposit = 1.0;
    annualInterest = 1.0;
    durationOfAction = 1;
}

//Constructor
BankReport::BankReport(const double initialAmount, const double deposit, const double annualInterest, const int durationOfAction) {
    this->initialAmount = initialAmount;
    this->deposit = deposit;
    this->annualInterest = annualInterest;
    this->durationOfAction = durationOfAction;
}

//Assessors
double BankReport::getInitialAmount() const {
    return initialAmount;
}

double BankReport::getDeposit() const {
    return deposit;
}

double BankReport::getAnnualInterest() const {
    return annualInterest;
}

int BankReport::getDurationOfAction() const {
    return durationOfAction;
}

//Mutators
void BankReport::setInitialAmount(const double newInitialAmount) {
    initialAmount = newInitialAmount;
}

void BankReport::setDurationOfAction(const int newYears) {
    durationOfAction = newYears;
}
void BankReport::setDeposit(const double newDeposit) {
    deposit = newDeposit;
}

void BankReport::setAnnualInterest(const double newAnnualInterest){ 
    annualInterest = newAnnualInterest;
}

//Print All Inputs
void BankReport::printInput() const {
    cout << left << fixed << setprecision(2);
    cout << setw(20) << "Initial Deposit" << ": " << initialAmount << endl;
    cout << setw(20) << "Deposit" << ": " << deposit << endl;
    cout << setw(20) << "Annual Interest" << ": " << annualInterest << endl;
    cout << setw(20) << "Months" << ": " << durationOfAction << endl;
}

//Print Reports
void BankReport::printReports() const {
    int width = 80;
    double monthlyInerestRate = annualInterest / 100 / 12;
    double totalBalance = initialAmount;
    double totalBalanceWithoutDeposit = initialAmount;
    double yearEndInerest = 0;

    printTableHeadWithout(width);

    // Without Deposits Report
    for (int year = 1; year <= durationOfAction; year++)    {
        yearEndInerest = 0; //reset for each year

        for (int month = 1; month <= 12; month++) {
            double monthlyInterest = totalBalance * monthlyInerestRate;
            yearEndInerest += monthlyInterest;

            //balance without monthly deposit
            totalBalance += monthlyInterest;
        }
        // Output of each year
        cout    << setw(6) << year
                << setw(20) << fixed << setprecision(2) << totalBalance
                << setw(30) << fixed << setprecision(2) << yearEndInerest << endl;
    }

    printTableHeadWith(width);

    // With Monthly Deposits Report
    for (int year = 1; year <= durationOfAction; year++)    {
        yearEndInerest = 0; //reset for each year

        for (int month = 1; month <= 12; month++) {
            double monthlyInterest = totalBalance * monthlyInerestRate;
            yearEndInerest += monthlyInterest;

            //balance with monthly deposit
            totalBalance += deposit + monthlyInterest;
        }
        // Output of each year
        cout    << setw(6) << year
                << setw(20) << fixed << setprecision(2) << totalBalance
                << setw(30) << fixed << setprecision(2) << yearEndInerest << endl;
    }
}

void printTableHeadWithout(int width) {  // Without Additional Monthly Deposits
    string line(width, '_');
    string lineTwo(width, '-');

    cout << lineTwo << endl;
    cout << setw(9) << "" << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << line << endl;
    cout << lineTwo << endl;
    cout << setw(6) << "Years" << setw(20) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
    cout << lineTwo << endl;
}

void printTableHeadWith(int width) {  // With Additional Monthly Deposits
    string line(width, '_');
    string lineTwo(width, '-');

    cout << lineTwo << endl;
    cout << setw(9) << "" << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << line << endl;
    cout << lineTwo << endl;
    cout << setw(6) << "Years" << setw(20) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
    cout << lineTwo << endl;
}
