#include"obiect.h"
#include "repository.h"
#include<iostream>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>
string RepoException::getMessage() {
	return msg;
}
void ObiectRepo::store(const Obiect& ob) {
	int index = cauta_dupa_titlu(ob.getTitlu());
	if (index != -1) {
		throw RepoException("Obiectul exista deja");
	}
	obiecte.push_back(ob);
}
int ObiectRepo::cauta_dupa_titlu(string titlu) const {
	auto index = find_if(obiecte.begin(), obiecte.end(), [&](const Obiect& o) {
		return  o.getTitlu() == titlu;
		}); 

	if (index != obiecte.end()) {
		int rez = index - obiecte.begin();
		return rez;
	}
	else {
		return -1;
	}
}
void ObiectRepo::sterge_repository(string titlu) {
	auto index = cauta_dupa_titlu(titlu);
	if (index == -1) {
		throw RepoException("obiectul nu exista!\n");
	}
	this->obiecte.erase(obiecte.begin() + index);

}
void ObiectRepo::modificare_repository(const Obiect& ob) {
	string titlu = ob.getTitlu();
	int index = cauta_dupa_titlu(titlu);
	if (index == -1) {
		throw RepoException("obiectul nu exista!\n");
	}
	this->obiecte[index] = ob;
}

vector<Obiect>& ObiectRepo::getAll() {
	return obiecte;
}
void ObiectRepoFile::loadFromFile() {
	ifstream in(filename);
	if (!in.is_open()) {
		throw RepoException("Unable to open file:" + filename);
	}
	while (!in.eof()) {
		string titlu;
		in >> titlu;
		if (titlu == "") {
			break;
		}
		string descriere;
		in >> descriere;
		string type;
		in >> type;
		double durata;
		in >> durata;
		if (in.eof()) {
			break;
		}
		Obiect o{ titlu,descriere,type,durata };
		ObiectRepoFile::store(o);


	}
	in.close();

}
void ObiectRepoFile::writeToFile() {
	ofstream out(filename);
	if (!out.is_open()) {
		string msg("Unable to open file:");
		throw RepoException(msg);
	}
	if (getAll().size() == 0) {
		out << "";
	}
	for (auto& o : getAll()) {
		out << o.getTitlu();
		out << endl;
		out << o.getDescriere();
		out << endl;
		out << o.getType();
		out << endl;
		out << o.getDurata();
		out << endl;
	}
	out.close();
}
