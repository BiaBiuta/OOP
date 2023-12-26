#pragma once
#include<vector>
#include"obiect.h"
#include"Observer.h"
#include"repository.h"
using namespace std;
class wish_list:public Observable {
private:
	vector<Obiect> cos;
	const ObiectRepo& rep;
public:
	wish_list(ObiectRepo& rep):rep{rep}{}
	void goleste_cos() ;
	void add(Obiect& ob);
	void genereaza(int x, vector<Obiect>v);
	const vector<Obiect>& getLista() const;
	void Export(string nume_fisier);
	vector<Obiect> get_allcos();
};