#include<iostream>
#include<vector>
#include<string>    
#include<algorithm>
using namespace std;

class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notify() = 0;
    virtual ~IChannel() {}
};  

class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;  
    string name;
    string latestVideo; 
public:
    Channel(const string& name)  {
        this->name = name;
    }
    void subscribe(ISubscriber* subscriber) override {
        if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }
    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }
    void notify() override {
        for (auto* subscriber : subscribers) {
            subscriber->update();
        }
    }

    void uploadVideo(const string& videoTitle) {
        latestVideo = videoTitle;
        cout << "Channel " << name << " uploaded a new video: " << latestVideo << endl;
        notify();
    }

    string getLatestVideo() const {
        return latestVideo;
    }

};


class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;
public:
    Subscriber(const string& name, Channel* channel) {
        this->name = name;
        this->channel = channel;
        //channel->subscribe(this);
    }
    void update() override {
        cout << "Subscriber " << name << " notified of new video: " << channel->getLatestVideo() << endl;
    }
};

int main() {
    Channel* channel = new Channel("TechGuru");
    Subscriber* subscriber1 = new Subscriber("Alice", channel);
    Subscriber* subscriber2 = new Subscriber("Bob", channel);

    channel->subscribe(subscriber1);
    channel->subscribe(subscriber2);

    channel->uploadVideo("C++ Observer Pattern Tutorial");

    channel->unsubscribe(subscriber1);

    channel->uploadVideo("C++17 Features Explained");

    delete subscriber1;
    delete subscriber2;
    delete channel;

    return 0;
}