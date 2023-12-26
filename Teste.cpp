#include "repository.h"
#include<assert.h>
#include"Teste.h"
#include<string>
#include<fstream>

void Teste::teste_repo() {
	vector < Obiect> v;
	Obiect o("a", "a", "a", 10);
	ObiectRepo rept(v);
	rept.store(o);
	try {
		rept.store(o);
	}
	catch (RepoException& e) {
		//cout << e.getMessage();
		assert(e.getMessage() == "Obiectul exista deja");
	}

	vector<Obiect> obiecte = rept.getAll();
	assert(obiecte.size() == 1);
	Obiect o1("a", "b", "a", 10);
	rept.modificare_repository(o1);
	assert(rept.getAll()[0].getDescriere() == "b");
	Obiect o2("b", "c", "d", 10);

	try {
		rept.modificare_repository(o2);
	}
	catch (RepoException& e) {
		cout << e.getMessage();
		assert(e.getMessage() == "obiectul nu exista!\n");
	}
	string titlu = "a";
	rept.sterge_repository(titlu);
	try {
		rept.sterge_repository(titlu);
	}
	catch (RepoException& e) {
		cout << e.getMessage();
		assert(e.getMessage() == "obiectul nu exista!\n");
	}

	assert(rept.getAll().size() == 0);
}
void Teste::teste_domain() {
	Obiect o("a", "a", "a", 10);
	assert(o.getDescriere() == "a");
	assert(o.getDurata() == 10);
	assert(o.getTitlu() == "a");
	assert(o.getType() == "a");
}
void Teste::teste_service() {
	vector<Obiect>obcte;
	ObiectRepo rept(obcte);
	Validare v;
	ObiectService sert(rept, v);
	string titlu = "a";
	string titlu_1 = "e";
	string descriere = "b";
	string descriere_1 = "c";
	string type1 = "c1";
	string type = "c";
	Obiect s("z", "a", "a", -1);
	try {
		sert.add_service(s.getTitlu(), s.getDescriere(), s.getType(), s.getDurata());
	}
	catch (ValidatorException& e) {
		cout << e.mesaj();
		assert(e.mesaj() == "durata invalid!\n");
	}
	Obiect s2("x", "", "a", 2);
	try {
		sert.add_service(s2.getTitlu(), s2.getDescriere(), s2.getType(), s2.getDurata());
	}
	catch (ValidatorException& e) {
		cout << e.mesaj();
		assert(e.mesaj() == "descriere invalid!\n");
	}
	Obiect s1("y", "a", "", 2);
	try {
		sert.add_service(s1.getTitlu(), s1.getDescriere(), s1.getType(), s1.getDurata());
	}
	catch (ValidatorException& e) {
		cout << e.mesaj();
		assert(e.mesaj() == "tip invalid!\n");
	}
	Obiect s3("", "a", "l", 2);
	try {
		sert.add_service(s3.getTitlu(), s3.getDescriere(), s3.getType(), s3.getDurata());
	}
	catch (ValidatorException& e) {
		cout << e.mesaj();
		assert(e.mesaj() == "titlu invalid!\n");
	}

	double durata = 12;
	sert.add_service(titlu, descriere, type, durata);

	assert(sert.getAll().size() == 1);
	sert.modifica_service_dupa_descriere(titlu, descriere_1);
	auto obiecte1 = sert.getAll();
	assert(obiecte1[0].getDescriere() == descriere_1);
	sert.modifica_service_dupa_tip(titlu, type1);
	auto obiecte2 = sert.getAll();
	assert(obiecte2[0].getType() == type1);
	double durata_1 = 11;
	sert.modifica_service_dupa_durata(titlu, durata_1);
	auto obiecte3 = sert.getAll();
	assert(obiecte3[0].getDurata() == durata_1);
	sert.sterge_service(titlu);
	auto obiecte4 = sert.getAll();
	assert(obiecte4.size() == 0);
	string cum1 = "descriere";
	string cum2 = "tip";
	string cum3 = "titlu";
	string ordine1 = "crescatoare";
	string ordine2 = "des";
	string titlu2 = "c";
	string titlu3 = "b";
	string titlu4 = "d";
	string descriere2 = "alergare";
	string descriere1 = "climbing";
	string descriere3 = "dartz";
	string descriere4 = "alergare";
	string tip5 = "m";
	string tip1 = "m";
	string tip2 = "f";
	string tip3 = "m";
	string tip4 = "m";
	double durata1 = 13;
	double durata5 = 12;
	double durata2 = 15;
	double durata3 = 13;
	double durata4 = 11;
	sert.add_service(titlu, descriere1, tip1, durata1);
	sert.add_service(titlu2, descriere2, tip2, durata2);
	sert.add_service(titlu3, descriere3, tip3, durata3);
	sert.add_service(titlu4, descriere4, tip4, durata4);
	vector<Obiect>lista1 = sert.sortare_service(cum1, ordine1);
	assert(lista1[0].getDescriere() == descriere2);
	assert(lista1[1].getDescriere() == descriere4);
	assert(lista1[2].getDescriere() == descriere1);
	assert(lista1[3].getDescriere() == descriere3);
	vector<Obiect> lista2 = sert.sortare_service(cum1, ordine2);
	assert(lista2[0].getDescriere() == descriere3);
	assert(lista2[1].getDescriere() == descriere1);
	assert(lista2[2].getDescriere() == descriere2);
	assert(lista2[3].getDescriere() == descriere4);
	vector<Obiect> lista3 = sert.sortare_service(cum2, ordine1);
	assert(lista3[0].getType() == tip2);
	assert(lista3[1].getType() == tip1);
	assert(lista3[2].getType() == tip3);
	assert(lista3[3].getType() == tip4);
	sert.add_service(titlu_1, descriere, tip5, durata5);
	vector<Obiect> lista4 = sert.sortare_service(cum2, ordine2);
	assert(lista4[0].getType() == tip4);
	assert(lista4[1].getType() == tip3);
	assert(lista4[2].getType() == tip1);
	assert(lista4[3].getType() == tip5);
	assert(lista4[4].getType() == tip2);
	vector<Obiect> lista5 = sert.sortare_service(cum3, ordine1);
	assert(lista5[0].getTitlu() == titlu);
	assert(lista5[1].getTitlu() == titlu3);
	assert(lista5[2].getTitlu() == titlu2);
	assert(lista5[3].getTitlu() == titlu4);
	assert(lista5[4].getTitlu() == titlu_1);
	vector<Obiect> lista6 = sert.sortare_service(cum3, ordine2);
	vector<Obiect> listafiltrata = sert.filtrare_dupa_descriere();
	assert(listafiltrata.size() == 2);
	vector<Obiect> listafiltrata2 = sert.filtrare_dupa_tip();
	assert(listafiltrata2.size() == 4);



}
void Teste::teste_undo() {
	vector<Obiect>obcte;
	ObiectRepo rept(obcte);
	Validare v;
	ObiectService sert(rept, v);

	string titlu = "a";
	string titlu_1 = "e";
	string descriere = "b";
	string descriere_1 = "c";
	string type1 = "c1";
	string type = "c";
	double durata = 12;
	double durata2 = 2;
	sert.add_service(titlu, descriere, type, durata);
	sert.undo();
	int index = rept.cauta_dupa_titlu(titlu);
	assert(index == -1);
	try {
		sert.undo();
	}
	catch (RepoException& e) {
		assert(e.getMessage() == "Nu mai exista operatii");
	}
	sert.add_service(titlu, descriere, type, durata);
	sert.sterge_service(titlu);
	sert.undo();
	assert(rept.cauta_dupa_titlu(titlu) != -1);
	sert.modifica_service_dupa_descriere(titlu, descriere_1);
	sert.undo();

	assert(sert.getAll()[0].getDescriere() == "b");
	sert.modifica_service_dupa_tip(titlu, type1);
	sert.undo();
	assert(sert.getAll()[0].getType() == type);
	sert.modifica_service_dupa_durata(titlu, durata2);
	sert.undo();
	assert(sert.getAll()[0].getDurata() == durata);
	sert.undo();


	sert.add_service(titlu, descriere, type, durata);
	sert.add_service(titlu_1, descriere, type1, durata2);
	std::map<std::string, vector<string>> map1 = sert.creaza_map();
	for (auto I : map1) {
		assert(I.first == descriere);
		assert(I.second[0] == titlu);
		assert(I.second[1] == titlu_1);
	}


}
void Teste::teste_cos() {
	vector<Obiect>obcte;
	ObiectRepo rept(obcte);
	Validare v;
	ObiectService sert(rept, v);
	string titlu = "a";
	string titlu_1 = "e";
	string descriere = "b";
	string descriere_1 = "c";
	string type1 = "c1";
	string type = "c";
	double durata = 12;
	double durata1 = 2;
	sert.add_service(titlu, descriere, type, durata);
	sert.add_service(titlu_1, descriere_1, type1, durata1);
	assert(sert.get_cos().size() == 0);
	sert.add_wish_list(titlu);
	assert(sert.get_cos().size() == 1);
	try {
		sert.add_wish_list("1ccc");
	}
	catch (RepoException&) {
		assert(true);
	}
	sert.goleste_cosul();
	assert(sert.get_cos().size() == 0);
	sert.genereaza(2);
	assert(sert.get_cos().size() == 2);

}
void Teste::teste_exporta() {
	vector<Obiect>obcte;
	ObiectRepo rept(obcte);
	Validare v;
	ObiectService sert(rept, v);
	string titlu = "a";
	string titlu_1 = "e";
	string descriere = "b";
	string descriere_1 = "c";
	string type1 = "c1";
	string type = "c";
	double durata = 12;
	double durata1 = 2;
	sert.add_service(titlu, descriere, type, durata);
	sert.add_service(titlu_1, descriere_1, type1, durata1);
	sert.genereaza(2);
	sert.Export("testExport.html");
	std::ifstream in("testExport.html");
	in.open("testExport.html");
	assert(in.is_open());
	sert.Export("a/b/c/Export");

}
void Teste::test_filerepo() {
	std::ofstream out("testObiecte.txt");
	out.close();//creez un fisier gol

	ObiectRepoFile repF2{ "testObiecte.txt" };
	repF2.store(Obiect{ "aaa","bbb","ccc",12 });
	//repF2.store(Obiect{ "rrr","ccc","sss",14 });
	auto p = repF2.cauta_dupa_titlu("aaa");
	vector<Obiect>lista = repF2.getAll();
	assert(lista[p].getDurata() == 12);
	int i = repF2.getAll().size();
	assert(repF2.getAll().size() == 1);
	try {
		repF2.store(Obiect{ "aaa","bbb","ddd",13 });
	}
	catch (RepoException&) {
	}
	repF2.modificare_repository(Obiect{ "aaa","bbb","ddd",15 });
	assert(repF2.getAll()[0].getDurata() == 15);
	repF2.sterge_repository("aaa");
	assert(repF2.getAll().size() == 0);

	try {
		repF2.sterge_repository("aaa");
	}
	catch (RepoException&) {
	}
	ObiectRepoFile repF3{ "testObiecte.txt" };
	assert(repF3.getAll().size() == 0);
	try {
		ObiectRepoFile repF4{ "te/stObiect.txt" };
	}
	catch (RepoException&) {
	}
	try {
		ObiectRepoFile{ "trevg.txt" }.store(Obiect{ "aaa","bbb","eee",13 });
	}
	catch (RepoException&) {
	}
}

