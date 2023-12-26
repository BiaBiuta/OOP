#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QLabel>
#include "obiect.h"
#include "service.h"
#include "MyTableModel.h"
#include "MyListWidget.h"
#include <vector>
#include"MyListWidget.h"
#include <QTableWidget>
#include"QtWidgetsApplication2.h"
#include"CosGUI.h"
class SmallGui :public QWidget {
private:
	QLabel* lbl = new QLabel("Nimic");
public:
	SmallGui() {
		QHBoxLayout* ly = new QHBoxLayout;
		setLayout(ly);
		ly->addWidget(lbl);

	}
	~SmallGui() = default;
	void setObiect(const Obiect& o) {
		lbl->setText(QString::fromStdString(o.getTitlu()));
	}
};
class ObiectGui :public QWidget {
private:
	ObiectService& serv;
	//MyList* model;
	CosGui& gui;
	QHBoxLayout* lyMain = new QHBoxLayout;
	QHBoxLayout* obiectelayout;
	MyListModel* lst;
	QListView* view = new QListView;
	QListWidget* lst2;
	QLineEdit* txtTitlu;
	QLineEdit* txtDescriere;
	QLineEdit* txtType;
	QLineEdit* txtDurata;
	QPushButton* btnadauga;
	QPushButton* btnremove;
	QPushButton* btnupdatedupadescriere;
	QPushButton* btnupdatedupatip;
	QPushButton* btnupdatedupadurata;
	QPushButton* btnfiltrare;
	QPushButton* btnsortare;
	QPushButton* btnFilterByDescriere;
	QPushButton* btnFilterByTip;
	QPushButton* remove;
	QPushButton* cos;
	QPushButton* cos2;
	QPushButton* adaugacos;

	QPushButton* Sortare;
	QPushButton* Undo;
	QLineEdit* ordine;
	QLineEdit* descriere;
	QPushButton* ok;
	QLabel* lbl2 = new QLabel("Nimic");
	QHBoxLayout* casutasortare = new QHBoxLayout;
	QVBoxLayout* lyBtnDy = new QVBoxLayout;

	QWidget* btnDyn = new QWidget;
	std::map<string, QPushButton*> butoane;
	int buttonPressCount = 0;
	QWidget* cosWindow = new QWidget;
	QListWidget* lista;
	QTableWidget* tablou;
	QPushButton* goleste;
	QPushButton* genereaza;
	QPushButton* exporta;
	QLineEdit* textGenereaza;
	QLineEdit* textExporta;
	void initGuiCmps();
	void casasortare();
	void reloadList(const std::vector<Obiect>& o);
	void reloadListCos(const std::vector<Obiect>& o);
	void connectSignalsSlots();
	//void adaugaButoane(const std::vector<Obiect>& o);
public:
	ObiectGui(ObiectService& serv) : serv{ serv }, gui{ gui } {
		initGuiCmps();
		reloadList(serv.getAll());
		connectSignalsSlots();
		//adaugaButoane();
		//reloadList(serv.getAll());
		
	}
	~ObiectGui() {
		//lbl2->clear();
		//lbl2->deleteLater();
	}
	void UNDO();
	void addObiect();
	void removeObiect();
	void sortareObiect();
	void updateObiect();
	void filtraredupatip();
	void filtraredupadescriere();
	void adaugaButoane();
	void sortar();
	void  handleButtonClick();
};