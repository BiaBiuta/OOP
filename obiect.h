#pragma once
#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::string;

class Obiect
{
private:
	string titlu;
	string descriere;
	string type;
	double durata;
public:
	double getDurata() const;
	string getType() const;
	string getDescriere() const;
	string getTitlu() const;
	Obiect() = default;
	Obiect(string titlu, string descriere, string type, double durata) : titlu{ titlu }, descriere{ descriere }, type{ type }, durata{ durata } {

	}

	Obiect(const Obiect& ot) :titlu{ ot.titlu }, descriere{ ot.descriere }, type{ ot.type }, durata{ ot.durata } {

	}
	~Obiect() = default;
	Obiect& operator=(const Obiect& o) {
		this->titlu = o.titlu;
		this->descriere = o.descriere;
		this->type = o.type;
		this->durata = o.durata;
		return *this;
	}
	string to_string()const  {
		return getTitlu() + getDescriere() + getType() + std::to_string(getDurata());
	}

};