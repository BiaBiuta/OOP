#pragma once
#include<vector>
#include<algorithm>
#include<qdebug.h>
class Observer
{
public:
	virtual void update() = 0;
	
};
class Observable{
private:
	std::vector<Observer*>observers;
public:
	void addObserver(Observer*observer) {
		observers.push_back(observer);
	}
	void stergeObserver(Observer* observer) {
		observers.erase(std::remove(observers.begin(), observers.end(), observer),observers.end());
	}
	void notify() {
		for (auto obs : observers) {
			qDebug() << "si eu";
			obs->update();
		}
	}
};

