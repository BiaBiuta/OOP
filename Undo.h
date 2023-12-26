#pragma once
#include "obiect.h"
#include "repository.h"
class ActiuneUndo {
public:

	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() = default;
};
class UndoAdauga :public ActiuneUndo {
	Obiect obiectadaugat;
	ObiectRepo& rep;
public:
	UndoAdauga(ObiectRepo& rep, const Obiect& obiectadaugat) :rep{ rep }, obiectadaugat{ obiectadaugat } {
	}
	void doUndo() override {
		rep.sterge_repository(obiectadaugat.getTitlu());
	}
};
class UndoSterge :public ActiuneUndo {
	Obiect obiectsters;
	ObiectRepo& rep;
public:
	UndoSterge(ObiectRepo& rep, const Obiect& obiectsters) :rep{ rep }, obiectsters{ obiectsters } {
	}
	void doUndo() override {
		rep.store(obiectsters);
	}
};
class UndoModifica :public ActiuneUndo {

	Obiect obiectmodificat;

	ObiectRepo& rep;
public:
	UndoModifica(ObiectRepo& rep, const Obiect& obiectmodificat) :rep{ rep }, obiectmodificat{ obiectmodificat } {
	}
	void doUndo() override {

		rep.modificare_repository(obiectmodificat);
	}
};