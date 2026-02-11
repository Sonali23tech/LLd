#include<iostream>
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

class BasicWheatBurger : public Burger{
public:         
    void prepare() override {
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};

class StandardWheatBurger : public Burger{
public: 
    void prepare() override {
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};  

class PremiumWheatBurger : public Burger{
public:         
    void prepare() override {
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

class BurgerFactory{
public:     
       virtual Burger* createBurger(const string& type) = 0;  //pure virtual function
};


class SinghBurger : public BurgerFactory{
public:     
    Burger* createBurger(const string& type) override {
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

class KingBurger : public BurgerFactory{
public:     
    Burger* createBurger(const string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        } else if (type == "premium") {
            return new PremiumWheatBurger();
        } else {
            return nullptr;
        }
    }
};  

int main() {
    BurgerFactory* factory1 = new SinghBurger();
    BurgerFactory* factory2 = new KingBurger();

    Burger* burger1 = factory1->createBurger("basic");
    Burger* burger2 = factory1->createBurger("standard");
    Burger* burger3 = factory1->createBurger("premium");

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

    Burger* burger4 = factory2->createBurger("basic");
    Burger* burger5 = factory2->createBurger("standard");
    Burger* burger6 = factory2->createBurger("premium");

    if (burger4) {
        burger4->prepare();
        delete burger4;  // Clean up memory
    }
    if (burger5) {
        burger5->prepare();
        delete burger5;  // Clean up memory
    }
    if (burger6) {
        burger6->prepare();
        delete burger6;  // Clean up memory
    }

    delete factory1;  // Clean up memory
    delete factory2;  // Clean up memory

    return 0;
}