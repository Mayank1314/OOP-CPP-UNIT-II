



#include <iostream>

#include <string>

using namespace std;


class Payment {

protected:

    double amount;

public:

    Payment(double value) : amount(value) {}

    virtual void process() const = 0;

    virtual ~Payment() = default;

};


class CardPayment : public Payment {

public:

    CardPayment(double value) : Payment(value) {}

    void process() const override {

        cout << "Processing card payment: Rs. " << amount << endl;

    }

};


class UpiPayment : public Payment {

public:

    UpiPayment(double value) : Payment(value) {}

    void process() const override {

        cout << "Processing UPI payment: Rs. " << amount << endl;

    }

};


int main() {

    CardPayment card(2500);

    UpiPayment upi(1200);

    card.process();

    upi.process();

}

