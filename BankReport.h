#ifndef BANKREPORT_H
#define BANKREPORT_H

class BankReport {
private:
    double initialAmount = 0.0;
    double deposit = 0.0;
    double annualInterest = 0.0;
    int durationOfAction = 0;

public:
    //Default Constructor
    BankReport();

    //Contrusctor
    BankReport(double initialAmount, double deposit, double annualInterest, int durationOfAction);

    //Accessors (Getters)
    double getInitialAmount() const;
    double getDeposit() const;
    double getAnnualInterest() const;
    int getDurationOfAction() const;

    //Mutators (Setters)
    void setInitialAmount(const double newInitialAmount);
    void setDeposit(const double newDeposit);
    void setAnnualInterest(const double newAnnualInterest);
    void setDurationOfAction(const int newYears);

    //Print Functions
    void printInput() const;
    void printReports() const;

};
    void anyKey(); // Any Key to Continue

#endif
