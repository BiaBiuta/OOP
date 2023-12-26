#pragma once
#pragma once
#include"obiect.h"
#include"service.h"
#include"repository.h"
//#include"vectordinamic.h.h"
#include"undo.h"

class Teste
{
private:

	/*vector<Obiect> obiecte;
	RepoException& msg;
	ObiectRepo& rept;
	ObiectService& servt;
	Validare& v;*/
public:
	/*Teste(RepoException& msg, ObiectRepo& rept, ObiectService& servt, Validare& v) : rept{ rept }, servt{ servt }, msg{ msg }, v{ v } {

	}*/
	Teste() = default;
	~Teste() = default;
	void teste_domain();
	void teste_repo();
	void teste_service();
	void teste_undo();
	void teste_cos();
	void teste_exporta();
	void test_filerepo();
	void testeAll() {
		teste_repo();
		teste_domain();
		teste_service();
		teste_undo();
		teste_cos();
		teste_exporta();
		test_filerepo();
	};


};