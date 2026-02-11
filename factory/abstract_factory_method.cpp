#include<iostream>
using namespace std;

class Burger {
public: 
    virtual void prepare() = 0;  //pure virtual function
    //virtual ~Burger(){};  //virtual destructor
};



class BasicBurger  : public Burger {
public:
    void prepare() override {
        cout << "Preparing Burger" << endl;
    }
};

class StandardBurger : public Burger {
public: 
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};  

class PremiumBurger : public Burger {
public:         
    void prepare() override {
        cout << "Preparing Premium Burger" << endl;
    }
};


class BasicWheatBurger  : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};

class StandardWheatBurger : public Burger {
public: 
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};  

class PremiumWheatBurger : public Burger {
public:         
    void prepare() override {
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};
class GarlicBread  {
public:
     virtual void prepare() =0;
    // virtual ~GarlicBurger(){};  //virtual destructor
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic GarlicBread" << endl;
    }
};

class CheeseGarlicBread : public GarlicBread {
public: 
    void prepare() override {
        cout << "Preparing Cheese Garlic Bread" << endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic GarlicBread" << endl;
    }
};

class CheeseWheatGarlicBread : public GarlicBread {
public: 
    void prepare() override {
        cout << "Preparing Cheese Garlic Bread" << endl;
    }
};






class MealFactory {
public:     
    virtual Burger* createBurger(const string& type) = 0;  //pure virtual function
    virtual GarlicBread* createGarlicBread(const string& type) = 0;  //pure virtual function
};

class SinghMealFactory : public MealFactory {
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

    GarlicBread* createGarlicBread(const string& type) override {
        if (type == "basic") {
            return new BasicGarlicBread();
        } else if (type == "standard") {
            return new CheeseGarlicBread();
        } 
         else {
            return nullptr;
        }
    }
};

class KingMealFactory : public MealFactory {
public:
    Burger* createBurger(const string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        }  else {
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(const string& type) override {
        if (type == "basic") {
            return new BasicWheatGarlicBread();
        } else if (type == "standard") {
            return new CheeseWheatGarlicBread();
         } else {
            return nullptr;
        }
    };
};


int main() {
    MealFactory* factory1 = new SinghMealFactory();
    MealFactory* factory2 = new KingMealFactory();

    Burger* burger1 = factory1->createBurger("basic");
    GarlicBread* bread1 = factory1->createGarlicBread("standard");

    if (burger1) {
        burger1->prepare();         
        delete burger1;  // Clean up memory
    }
    if (bread1) {
        bread1->prepare();
        delete bread1;  // Clean up memory
    }

    Burger* burger2 = factory2->createBurger("standard");
    GarlicBread* bread2 = factory2->createGarlicBread("standard");

    if (burger2) {
        burger2->prepare();
        delete burger2;  // Clean up memory
    }
    if (bread2) {
        bread2->prepare();
        delete bread2;  // Clean up memory
    }

    delete factory1;  // Clean up memory
    delete factory2;  // Clean up memory

    return 0;
}