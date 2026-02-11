#include <iostream>

using namespace std;

class Burger{
public:
    virtual void prepare() = 0;  //pure virtual function
    virtual ~Burger(){};  //virtual destructor

};

class BasicBurger : public Burger{
public:
    void prepare() override {
        cout << "Preparing Basic Burger" << endl;
    }
};


class StandardBurger : public Burger{
public:
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger{
public:         
    void prepare() override {
        cout << "Preparing Premium Burger" << endl;
    }
};

class BurgerFactory{
public:     
    static Burger* createBurger(const string& type) {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            return nullptr;
        }
    }
};


int main() {
    Burger* burger1 = BurgerFactory::createBurger("basic");
    Burger* burger2 = BurgerFactory::createBurger("standard");
    Burger* burger3 = BurgerFactory::createBurger("premium");

    if (burger1) {
        burger1->prepare();
        delete burger1;  // Clean up memory
    }
    if (burger2) {
        burger2->prepare();
        delete burger2;  // Clean up memory
    }
    if (burger3) {
        burger3->prepare();
        delete burger3;  // Clean up memory
    }

    return 0;
}

