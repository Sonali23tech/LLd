#include<iostream>
using namespace std;

class Singleton {
private:    
    static Singleton* instance;  // Static pointer to the single instance

    // Private constructor to prevent instantiation
    Singleton() {
        cout << "Singleton instance created." << endl;
    }

public:
    // Static method to provide access to the instance  
    static Singleton* getInstance() {
        if (instance == nullptr) {  // Check if instance already exists
            instance = new Singleton();  // Create the instance if it doesn't exist
        }
        return instance;  // Return the single instance
     }
};

// Initialize the static member variable
Singleton* Singleton::instance = nullptr;       
int main() {
    Singleton* s1 = Singleton::getInstance();  // Creates the instance
    Singleton* s2 = Singleton::getInstance();  // Returns the existing instance

    if (s1 == s2) {
        cout << "Both pointers point to the same instance." << endl;
    } else {
        cout << "Different instances exist." << endl;
    }

    return 0;
}
