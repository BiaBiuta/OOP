#include "repository.h"
//#include "vectordinamic.h"
#include "obiect.h"
#include "repository.h"
#include "service.h"
#include<algorithm>
#include<functional>
#include<vector>
#include<memory>
#include<set>
#include"Undo.h"
//#include <WinUser.h>
using std::vector;
void ObiectService::add_service(string titlu, string descriere, string type, double durata) {
	Obiect o(titlu, descriere, type, durata);
	v.validareObiect(o);
	rep.store(o);
	undoActions.push_back(std::make_unique<UndoAdauga>(rep, o));

}
void  ObiectService::sterge_service(string titlu) {
	int index = rep.cauta_dupa_titlu(titlu);
	Obiect o = rep.getAll()[index];
	rep.sterge_repository(titlu);
	undoActions.push_back(std::make_unique<UndoSterge>(rep, o));
}
const vector<Obiect>& ObiectService::getAll() const {
	return rep.getAll();
}
void ObiectService::modifica_service_dupa_descriere(string titlu, string descriere) {
	int index = rep.cauta_dupa_titlu(titlu);
	Obiect o1 = rep.getAll()[index];
	string type = this->rep.getAll()[index].getType();
	double durata = this->rep.getAll()[index].getDurata();
	Obiect o(titlu, descriere, type, durata);
	v.validareObiect(o);
	rep.modificare_repository(o);
	undoActions.push_back(std::make_unique<UndoModifica>(rep, o1));
}
void ObiectService::modifica_service_dupa_tip(string titlu, string tip) {
	int index = rep.cauta_dupa_titlu(titlu);
	Obiect  o1 = rep.getAll()[index];
	string descriere = this->rep.getAll()[index].getDescriere();
	double durata = this->rep.getAll()[index].getDurata();
	Obiect o(titlu, descriere, tip, durata);
	rep.modificare_repository(o);
	undoActions.push_back(std::make_unique<UndoModifica>(rep, o1));
}
void ObiectService::modifica_service_dupa_durata(string titlu, double durata) {
	int index = rep.cauta_dupa_titlu(titlu);
	Obiect o1 = rep.getAll()[index];
	string descriere = this->rep.getAll()[index].getDescriere();
	string tip = this->rep.getAll()[index].getType();
	Obiect o(titlu, descriere, tip, durata);


	rep.modificare_repository(o);
	undoActions.push_back(std::make_unique<UndoModifica>(rep, o1));

}



vector<Obiect> ObiectService::sortare_service(string cum, string ordine) {
	 sortere = rep.getAll();
	if (cum == "descriere") {
		if (ordine == "crescatoare") {
			sort(sortere.begin(), sortere.end(), [](Obiect& o1, Obiect& o2) {
				return o1.getDescriere() < o2.getDescriere(); });
		}
		else {
			sort(sortere.begin(), sortere.end(), [](Obiect& o1, Obiect& o2) {
				return o1.getDescriere() > o2.getDescriere(); });
		}
	}
	else if (cum == "tip") {
		if (ordine == "crescatoare") {

			sort(sortere.begin(), sortere.end(), [](Obiect& o1, Obiect& o2) {
				if (o1.getType() == o2.getType()) {
					return o1.getDurata() < o2.getDurata();
				}
				return o1.getType() < o2.getType(); });
		}
		else {
			sort(sortere.begin(), sortere.end(), [](Obiect& o1, Obiect& o2) {
				if (o1.getType() == o2.getType()) {
					return o1.getDurata() > o2.getDurata();
				}
				return o1.getType() > o2.getType(); });
		}


	}
	else if (cum == "titlu") {
		if (ordine == "crescatoare") {
			sort(sortere.begin(), sortere.end(), [](Obiect& o1, Obiect& o2) {
				return o1.getTitlu() < o2.getTitlu(); });
		}
		else {
			sort(sortere.begin(), sortere.end(), [](Obiect& o1, Obiect& o2) {
				return o1.getTitlu() > o2.getTitlu(); });
		}
	}
	return sortere;
}
vector<Obiect> ObiectService::filtrare(function<bool(const Obiect&)> fct) {
	vector<Obiect>listafiltrata;

	for (const auto& obiect : rep.getAll()) {
		if (fct(obiect)) {
			listafiltrata.push_back(obiect);
		}
	}
	return listafiltrata;
}
vector<Obiect> ObiectService::filtrare_dupa_descriere() {
	return filtrare([=](const Obiect& o) {
		return o.getDescriere()[0] == 'a';
		});

}
vector<Obiect> ObiectService::filtrare_dupa_tip() {
	return filtrare([=](const Obiect& o) {
		return o.getType()[0] == 'm';
		});

}
const vector<Obiect> ObiectService::goleste_cosul() {
	this->cos.goleste_cos();
	//notify();
	return cos.getLista();
}
const vector<Obiect>& ObiectService::add_wish_list(const string& titlu) {
	int index = rep.cauta_dupa_titlu(titlu);
	if (index == -1) {
		throw RepoException("obiectul nu exista !");
	}
	Obiect o = rep.getAll()[index];

	this->cos.add(o);
	return cos.getLista();
}
const vector<Obiect> ObiectService::genereaza(int x) {
	this->cos.genereaza(x, rep.getAll());
	//notify();
	return cos.getLista();
}
vector<Obiect> ObiectService::get_cos() {
	return this->cos.getLista();
}
void ObiectService::Export(string nume_fisier) {
	unsigned int n = nume_fisier.length(), nr = 0;
	for (int i = 0; i < n; i++)
		if (nume_fisier.at(i) == '.')
			nr++;

	if (nr != 1)
		nume_fisier += ".html";
	this->cos.Export(nume_fisier);
}
vector<Obiect> ObiectService:: get_all_cos() {
	return this->cos.get_allcos();
}
void ObiectService::undo() {
	if (undoActions.empty()) {
		throw RepoException{ "Nu mai exista operatii" };
	}
	else {
		undoActions.back()->doUndo();
		undoActions.pop_back();
	}
}

void ObiectService::mapul(string type) {
	vector<string> S;
	
	for (const auto& obiect : rep.getAll()) {
		if (obiect.getDescriere() == type) {

			S.push_back(obiect.getTitlu());
		}

	}
	ma[type] = S;
	
}
std::map<std::string, vector<string>> ObiectService::creaza_map() {
	for (const auto& obiect : rep.getAll()) {
		if (ma.count(obiect.getDescriere()) == 0) {
			mapul(obiect.getDescriere());
		}
	}
	map<string,vector<string>> mi = ma;
	ma.clear();
	return mi;
}
wish_list& ObiectService:: getCos() {
	return this->cos;
}



