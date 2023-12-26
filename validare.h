#pragma once
#include<string>
#include<vector>
#include"obiect.h"
#include"repository.h"
//#include"vectordinamic.h"
using std::string;
class ValidatorException {

	vector<string> msg;
public:
	ValidatorException(vector<string> m) :msg{ m } {
	}
	string mesaj() {
		string mesaje = "";
		for (int i = 0; i < msg.size(); i++) {
			mesaje = mesaje + msg[i] + "\n";

		}
		return mesaje;
	}

};
class Validare {
	friend ValidatorException;

public:

	void validareObiect(const Obiect& obiect) {
		vector<string> exceptie;
		if (obiect.getDurata() < 0) {
			exceptie.push_back("durata invalid!");
		}
		if (obiect.getType() == "") {
			exceptie.push_back("tip invalid!");
		}
		if (obiect.getDescriere() == "") {
			exceptie.push_back("descriere invalid!");
		}
		if (obiect.getTitlu() == "") {
			exceptie.push_back("titlu invalid!");
		}
		if (exceptie.size() > 0)
			throw ValidatorException(exceptie);
	}
};
