#include<iostream>
#include<string>
using namespace std;

class Command {
public: 
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
};

class Light {
public:    void on() {  
        cout << "Light is ON" << endl;
    }   
    void off() {
        cout << "Light is OFF" << endl;
    }
};

class Fan{
    public:    void on() {
        cout << "Fan is ON" << endl;
    }   
    void off() {
        cout << "Fan is OFF" << endl;
    }

};

class LightOnCommand : public Command {
private:    Light* light;
public:    LightOnCommand(Light* l) {
        this->light = l;
    }
    void execute() override {
        light->on();
    }
    void undo() override {
        light->off();
    }
};

class LightOffCommand : public Command {
private:    Light* light;       
public:    LightOffCommand(Light* l) {
        this->light = l;
    }
    void execute() override {
        light->off();
    }
    void undo() override {
        light->on();
    }
};

class FanOnCommand : public Command {
private:    Fan* fan;   
public:    FanOnCommand(Fan* f) {
        this->fan = f;
    }
    void execute() override {
        fan->on();
    }
    void undo() override {
        fan->off();
    }
};

class FanOffCommand : public Command {
private:    Fan* fan;
public:    FanOffCommand(Fan* f) {
        this->fan = f;
    }
    void execute() override {
        fan->off();
    }
    void undo() override {
        fan->on();
    }
};

class RemoteControl {
private:    
 static const int SLOT_NUM = 4;
 Command* buttons[SLOT_NUM];
 bool buttonStates[SLOT_NUM]; // true for ON, false for OFF
public:    
    RemoteControl() {
        for (int i = 0; i < SLOT_NUM; i++) {
            buttons[i] = nullptr;
            buttonStates[i] = false;
        }
    }
    void setCommand(int slot, Command* command) {
        if (slot >= 0 && slot < SLOT_NUM) {
            if (buttons[slot]) {
                delete buttons[slot]; // Clean up existing command
            }
            buttons[slot] = command;
            buttonStates[slot] = false; // Default state is OFF
        }
    }
    void pressButton(int slot) {        
        if (slot >= 0 && slot < SLOT_NUM && buttons[slot]) {
            if (!buttonStates[slot]) {
                buttons[slot]->execute();
                buttonStates[slot] = true; // Set state to ON
            } else {
                buttons[slot]->undo();
                buttonStates[slot] = false; // Set state to OFF
            }
         }else{
            cout << "No command assigned to this slot." << endl;
         }
    }

    ~RemoteControl() {
        for (int i = 0; i < SLOT_NUM; i++) {
            if (buttons[i]) {
                delete buttons[i];
            }
        }
    }


    // void pressUndo(int slot) {
    //     if (slot >= 0 && slot < SLOT_NUM && buttons[slot]) {

    //         buttons[slot]->undo();
    //     }
    // }
};

int main() {
    Light* livingRoomLight = new Light();
    Fan* ceilingFan = new Fan();



    // Command* lightOn = new LightOnCommand(livingRoomLight);
    // Command* lightOff = new LightOffCommand(livingRoomLight);
    // Command* fanOn = new FanOnCommand(ceilingFan);
    // Command* fanOff = new FanOffCommand(ceilingFan);

    RemoteControl remote;

    remote.setCommand(0 , new LightOnCommand(livingRoomLight));
    remote.pressButton(0); // Light is ON
    remote.pressButton(0);   // Light is OFF

    remote.setCommand(1 , new FanOnCommand(ceilingFan));
    remote.pressButton(1); // Fan is ON
    remote.pressButton(1);   // Fan is OFF

    // delete lightOn;
    // delete lightOff;
    // delete fanOn;
    // delete fanOff;
    delete livingRoomLight;
    delete ceilingFan;
 
    return 0;
}