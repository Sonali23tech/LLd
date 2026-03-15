#include<iostream>
#include<string>

using namespace std;


// strategy for walking behavior of a robot
class WalkableRobot{

public:    virtual void walk() = 0;
    virtual ~WalkableRobot() {} 
};  

class NormalWalk : public WalkableRobot {
public:    void walk() override {
        cout << "Walking Robot" << endl;
    }

};

class NoWalk : public WalkableRobot {
public:    void walk() override {
        cout << "Not walking" << endl;
    }
};

//strategy for talking behavior of a robot
class TalkableRobot {
public:    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

class NormalTalk : public TalkableRobot {
public:    void talk() override {

        cout << "Talking Robot" << endl;
    }
};  

class NoTalk : public TalkableRobot {
public:    void talk() override {
        cout << "Not talking" << endl;
    }
};  

//strategy for flying behavior of a robot
class FlyableRobot {
public:    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:    void fly() override {
        cout << "Flying Robot" << endl;
    }
};

class NoFly : public FlyableRobot {
public:    void fly() override {
        cout << "Not flying" << endl;
    }
};


class Robot {
private:    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

public:    Robot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly) {
        this->walkBehavior = walk;
        this->talkBehavior = talk;
        this->flyBehavior = fly;
    }

    void performWalk() {
        walkBehavior->walk();
    }

    void performTalk() {
        talkBehavior->talk();
    }
    void performFly() {
        flyBehavior->fly();
    }

    virtual void projection() =0; //abstract method for projection behavior of a robot
};

class companionRobot : public Robot {
public:    companionRobot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly) : Robot(walk, talk, fly) {}
    void projection() override {
        cout << "Projection: Companion Robot" << endl;
    }
};

class workerRobot : public Robot {
public:    workerRobot(WalkableRobot* walk, TalkableRobot* talk, FlyableRobot* fly) : Robot(walk, talk, fly) {}
    void projection() override {
        cout << "Projection: Worker Robot" << endl;
    }
};

int main() {
    Robot* robot1 = new companionRobot(new NormalWalk(), new NormalTalk(), new NormalFly());
    cout << "Robot 1: " << endl;
    robot1->performWalk();
    robot1->performTalk();
    robot1->performFly();
    robot1->projection();

    Robot* robot2 = new workerRobot(new NoWalk(), new NormalTalk(), new NoFly());
    cout << "\nRobot 2: " << endl;
    robot2->performWalk();
    robot2->performTalk();
    robot2->performFly();
    robot2->projection();

    delete robot1;
    delete robot2;

    return 0;
}