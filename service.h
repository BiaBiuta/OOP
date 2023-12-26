#pragma once
#pragma once
#include <string>
#include <functional>
#include <memory>
#include <vector>
#include"obiect.h"
#include"repository.h"
//#include"vectordinamic.h"
#include"validare.h"
#include"wishlist.h"
#include"Undo.h"
#include<map>
using std::map;

using std::vector;
using std::unique_ptr;
using std::string;
class ObiectService:public Observable {
private:
	map < std::string, vector<string>> ma;
	wish_list cos;
	ObiectRepo& rep;
	Validare& v;
	vector<Obiect>sortere;
	vector<unique_ptr<ActiuneUndo>> undoActions;

public:

	ObiectService(ObiectRepo& rep, Validare& v) :rep{ rep }, v{ v } ,cos { cos } {

	}
	ObiectService(const ObiectRepo& ot) = delete;
	ObiectService() = default;
	~ObiectService() = default;
	void add_service(string titlu, string descriere, string type, double durata);
	void sterge_service(string titlu);
	
	void modifica_service_dupa_descriere(string titlu, string descriere);
	void modifica_service_dupa_tip(string titlu, string tip);
	void modifica_service_dupa_durata(string titlu, double durata);
	void swap(Obiect& o1, Obiect& o2);

	vector<Obiect> sortare_service(string cum, string ordine);
	vector<Obiect> sortare(string cum, string ordine);
	const vector<Obiect>& getAll() const;
	vector<Obiect>filtrare_dupa_descriere();
	vector<Obiect>filtrare_dupa_tip();
	vector<Obiect> filtrare(function<bool(const Obiect&)> fct);

	const vector<Obiect> goleste_cosul();
	const vector<Obiect>& add_wish_list(const string& titlu);
	const vector<Obiect> genereaza(int x);
	vector<Obiect>get_cos();
	void Export(string nume_fisier);
	vector<Obiect> filt_map(string type);
	vector<Obiect> get_all_cos();
	void undo();
	void mapul(string type);
	std::map<std::string, vector<string>> creaza_map();
	wish_list& getCos();
};
