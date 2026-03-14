#include<iostream>
#include<string>
using namespace std;

class Character {
public:
    virtual  string getAbilities() const = 0;
    virtual ~Character() {}
};

class Mario : public Character {
public:   string getAbilities() const override {
        return "Mario";
    }
};  


class CharacterDecorator : public Character {
protected:    Character* character;
public:    
    CharacterDecorator(Character*  c)  {
        this->character =  c;
    }
    
};

class HeightUpDecorator : public CharacterDecorator {
public:    HeightUpDecorator(Character* c) : CharacterDecorator(c) {}
    string getAbilities() const override {
        return character->getAbilities() + " with Height Up";
    }
};

class GunPowerDecorator : public CharacterDecorator {
public:    GunPowerDecorator(Character* c) : CharacterDecorator(c) {}
    string getAbilities() const override {
        return character->getAbilities() + " with Gun Power";
    }
};

class StarPowerDecorator : public CharacterDecorator {
public:    StarPowerDecorator(Character* c) : CharacterDecorator(c) {}
    string getAbilities() const override {
        return character->getAbilities() + " with Star Power";
    }
    ~StarPowerDecorator() {
        delete character;
    }
};


int main() {
    Character* mario = new Mario();
    cout << mario->getAbilities() << endl;

    Character* heightUpMario = new HeightUpDecorator(mario);
    cout << heightUpMario->getAbilities() << endl;

    Character* gunPowerMario = new GunPowerDecorator(heightUpMario);
    cout << gunPowerMario->getAbilities() << endl;

    Character* starPowerMario = new StarPowerDecorator(gunPowerMario);
    cout << starPowerMario->getAbilities() << endl;

    delete starPowerMario; // This will also delete the underlying decorators and the original Mario
    return 0;
}   