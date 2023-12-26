#pragma once
#pragma once
//#include"vectordinamic.h"
#include "obiect.h"
#include <vector>
using namespace std;


class RepoException
{
	string msg;
public:
	RepoException(string m) :msg{ m } {

	}
	string getMessage();
};
class ObiectRepo
{
private:
	vector<Obiect>obiecte;
public:
	ObiectRepo(const vector<Obiect>& obiecte) :obiecte{ obiecte } {}
	ObiectRepo(const ObiectRepo& ot) = delete;
	ObiectRepo() = default;
	~ObiectRepo() = default;
	virtual void store(const Obiect& ob);
	virtual vector<Obiect>& getAll() ;
	virtual void sterge_repository(string titlu);
	virtual int cauta_dupa_titlu(string titlu) const;
	virtual void modificare_repository(const Obiect& ob);
};
class ObiectRepoFile : public ObiectRepo {
private:
	string filename;

public:
	void loadFromFile();
	void writeToFile();
	void empty();

	explicit ObiectRepoFile(string filename) : ObiectRepo(), filename{ filename } {
		loadFromFile();
	}
	~ObiectRepoFile() = default;
	void store(const Obiect& ob) override {
		//loadFromFile();
		ObiectRepo::store(ob);//apelam metoda din clasa principala
		writeToFile();
	}
	void sterge_repository(string titlu) override {
		//loadFromFile();
		ObiectRepo::sterge_repository(titlu);//apelam metoda din clasa principala
		writeToFile();
	}
	int cauta_dupa_titlu(string titlu) {
		//loadFromFile();
		return ObiectRepo::cauta_dupa_titlu(titlu);
	}
	vector<Obiect>& getAll() override{
		//loadFromFile();
		return ObiectRepo::getAll();
	}
	void modificare_repository(const Obiect& ob) {
		//loadFromFile();
		ObiectRepo::modificare_repository(ob);
		writeToFile();
	}

};