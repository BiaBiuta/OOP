#pragma once
#include <qwidget.h>
#include <qtimer.h>
#include <QtWidgets/QHBoxLayout>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qtablewidget.h>
#include <qstring.h>
#include <qlabel.h>
#include <vector>
#include"qwidget.h"
#include"wishlist.h"
#include"service.h"
#include "MyTableModel.h"
#include "MyListWidget.h"
class CosGui:public QWidget, public Observer
{
private:
	wish_list& cos;
	QWidget* wid;
	ObiectService& serv;
	QHBoxLayout* lymain = new QHBoxLayout;

	MyTableModel* lst;
	QTableView* tabview = new QTableView;
	QPushButton* adauga;
	QPushButton* genereaza;
	QPushButton* exporta;
	QPushButton* sterge;
	QLineEdit* numar;
public:
	CosGui(wish_list& cos, ObiectService& serv) :cos{ cos }, serv{ serv } {
		initGui();
		cos.addObserver(this);
		reloadList1(cos.getLista());
		connection();
	}
	
	void initGui();
	void reloadList1( const vector<Obiect>& vec);
	void connection();
	void update() override {
		qDebug() << "acum";
		reloadList1(cos.getLista());
	}
	~CosGui() {
		cos.stergeObserver(this);
	}
};

