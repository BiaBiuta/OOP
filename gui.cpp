#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <qpalette.h>
#include <QTableWidget>
#include <qbrush.h>
#include <qdebug.h>
#include <string>
#include<set>
#include<map>
#include <algorithm>
#include <QDesktopServices>
#include <QUrl>
#include "MyTableModel.h"
#include "MyListWidget.h"
#include"gui.h"
#include"Histograma.h"
void ObiectGui:: casasortare() {
	lbl2->setLayout(casutasortare);
	if (lbl2->text() == "Nimic") {
		lbl2->setText("");
		QWidget* widdstanga = new QWidget;
		QVBoxLayout* vl = new QVBoxLayout;
		widdstanga->setLayout(vl);
		lst2 = new QListWidget;
		vl->addWidget(lst2);
		QWidget* widDetalii = new QWidget;
		QFormLayout* formLdetalii = new QFormLayout;
		widDetalii->setLayout(formLdetalii);
		descriere = new QLineEdit;
		formLdetalii->addRow(new QLabel("descriere"), descriere);
		ordine = new QLineEdit;
		formLdetalii->addRow(new QLabel("ordine"), ordine);

		QWidget* butoanestanga = new QWidget;
		QHBoxLayout* lybtnstg = new QHBoxLayout;
		butoanestanga->setLayout(lybtnstg);
		ok = new QPushButton("OK");
		formLdetalii->addWidget(ok);
		btnDyn->setLayout(lyBtnDy);
		casutasortare->addWidget(widDetalii);
		casutasortare->addWidget(btnDyn);
	}
		lbl2->show();
	


}

void ObiectGui::initGuiCmps() {
	setLayout(lyMain);
	QWidget* widdstanga = new QWidget;
	QVBoxLayout* vl = new QVBoxLayout;
	widdstanga->setLayout(vl);
	/*lst = new QListWidget;
	vl->addWidget(lst)*/;
	vl->addWidget(view);
	QWidget* butoanestanga = new QWidget;
	QHBoxLayout* lybtnstg = new QHBoxLayout;
	butoanestanga->setLayout(lybtnstg);
	btnfiltrare = new QPushButton("Filtrare");
	lybtnstg->addWidget(btnfiltrare);
	btnsortare = new QPushButton("Sortare");

	lybtnstg->addWidget(btnsortare);
	vl->addWidget(butoanestanga);
	lyMain->addWidget(widdstanga);

	QWidget* widDetalii = new QWidget;
	QFormLayout* formLdetalii = new QFormLayout;
	widDetalii->setLayout(formLdetalii);
	txtTitlu = new QLineEdit;
	formLdetalii->addRow(new QLabel("Titlu"), txtTitlu);
	txtDescriere = new QLineEdit;
	formLdetalii->addRow(new QLabel("Descriere"), txtDescriere);
	txtType = new QLineEdit;
	formLdetalii->addRow(new QLabel("Tip"), txtType);
	txtDurata = new QLineEdit;
	formLdetalii->addRow(new QLabel("Durata"), txtDurata);

	btnadauga = new QPushButton("Adauga");
	formLdetalii->addWidget(btnadauga);
	btnremove = new QPushButton("Remove");
	formLdetalii->addWidget(btnremove);
	btnupdatedupadescriere = new QPushButton("Update descriere");
	formLdetalii->addWidget(btnupdatedupadescriere);
	btnupdatedupatip = new QPushButton("Update tip");
	formLdetalii->addWidget(btnupdatedupatip);
	btnupdatedupadurata = new QPushButton("Update durata");
	formLdetalii->addWidget(btnupdatedupadurata);
	btnFilterByDescriere = new QPushButton("Filtrare descriere");
	formLdetalii->addWidget(btnFilterByDescriere);
	btnFilterByTip = new QPushButton("Filtrare tip");
	formLdetalii->addWidget(btnFilterByTip);
	Undo = new QPushButton("Undo");
	formLdetalii->addWidget(Undo);
	adaugacos = new QPushButton("adaugacos");
	formLdetalii->addWidget(adaugacos);
	cos = new QPushButton("cos");
	formLdetalii->addWidget(cos);
	cos2 = new QPushButton("cos2");
	formLdetalii->addWidget(cos2);
	lyMain->addWidget(widDetalii);
	btnDyn->setLayout(lyBtnDy);
	lyMain->addWidget(btnDyn);
	cosWindow->setWindowTitle("Cos de inchirieri");
	QHBoxLayout* cosLy = new QHBoxLayout;
	cosWindow->setLayout(cosLy);

	tablou = new QTableWidget;
	tablou->setColumnCount(3);
	//tablou->insertColumn(1);
	tablou->setRowCount(10);
	
	cosLy->addWidget(tablou);

	QWidget* cosRightWid = new QWidget;
	QVBoxLayout* cosRightLy = new QVBoxLayout;
	cosRightWid->setLayout(cosRightLy);

	QWidget* cosForm = new QWidget;
	QFormLayout* cosFormLy = new QFormLayout;
	cosForm->setLayout(cosFormLy);
	textGenereaza = new QLineEdit;
	cosFormLy->addRow(new QLabel("nr:obiecte"), textGenereaza);
	textExporta = new QLineEdit;
	cosFormLy->addRow(new QLabel("Nume fisier:"), textExporta);
	cosRightLy->addWidget(cosForm);

	QWidget* cosUnderBtn = new QWidget;
	QVBoxLayout* cosUnderLy = new QVBoxLayout;
	cosUnderBtn->setLayout(cosUnderLy);
	goleste = new QPushButton("GolesteCos");
	cosUnderLy->addWidget(goleste);
	genereaza = new QPushButton("GenereazaCos");
	cosUnderLy->addWidget(genereaza);
	exporta = new QPushButton("ExportCos");
	cosUnderLy->addWidget(exporta);
	cosRightLy->addWidget(cosUnderBtn);

	cosLy->addWidget(cosRightWid);
}
void ObiectGui::sortar() {
	qDebug() << "//am ajuns aici!!!";	
	disconnect(ok, &QPushButton::clicked, this, &ObiectGui::sortar);
	//reloadList(serv.getAll());
	qDebug() << descriere->text().toStdString() << ordine->text().toStdString();
	//if (descriere->text().toStdString() != "" and ordine->text().toStdString() != "") {
		//lst->clear();
		vector<Obiect> sortedList = serv.sortare_service(descriere->text().toStdString(), ordine->text().toStdString());
		//qDebug() << descriere->text().toStdString() << ordine->text().toStdString();
		/*for (const Obiect& objec : sortedList) {
			auto str = QString::fromStdString(objec.getTitlu());
			lst->addItem(str);
		}*/
		reloadList(sortedList);
		descriere->clear();
		ordine->clear();
		lbl2->hide();
    //}
	//connect(btnsortare, &QPushButton::clicked, this, &ObiectGui::sortareObiect);
}
void ObiectGui::sortareObiect() {
	casasortare();
	qDebug() << "am ajuns aici!!!";
	qDebug() << descriere->text().toStdString() << ordine->text().toStdString();
	QObject::connect(ok, &QPushButton::clicked, this, &ObiectGui::sortar);
	qDebug() << "been here";
}
void ObiectGui::UNDO() {
	serv.undo();
	reloadList(serv.getAll());
}
void ObiectGui::addObiect() {
	try {
		auto titlu= this->txtTitlu->text().toStdString();
		auto descriere= this->txtDescriere->text().toStdString();
		auto tip= this->txtType->text().toStdString();
		auto durata= this->txtDurata->text().toStdString();
		if (titlu.empty() || descriere.empty() || tip.empty()) {
			QMessageBox::information(this, "Something went wrong", "Something went wrong");
			return;
		}
		serv.add_service(txtTitlu->text().toStdString(), txtDescriere->text().toStdString(), txtType->text().toStdString(), txtDurata->text().toDouble());
		reloadList(serv.getAll());
		txtTitlu->setText("");
		txtDescriere->setText("");
		txtType->setText("");
		txtDurata->setText("");
		
		
	}
	catch (RepoException& ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
	}
	

}

void ObiectGui::updateObiect() {
	QPushButton* button = qobject_cast<QPushButton*>(sender());
	if (button==btnupdatedupadescriere)
	{
		try {
		serv.modifica_service_dupa_descriere(txtTitlu->text().toStdString(),txtDescriere->text().toStdString());
		reloadList(serv.getAll());
		txtTitlu->setText("");
		txtDescriere->setText("");
		txtType->setText("");
		txtDurata->setText("");
	}
	catch (RepoException& ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
	}
	}
	else if (button == btnupdatedupatip) {
		try {
			serv.modifica_service_dupa_tip(txtTitlu->text().toStdString(), txtType->text().toStdString());
			reloadList(serv.getAll());
			txtTitlu->setText("");
			txtDescriere->setText("");
			txtType->setText("");
			txtDurata->setText("");
		}
		catch (RepoException& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
		}
	}
	else if (button == btnupdatedupadurata) {
		try {
			serv.modifica_service_dupa_durata(txtTitlu->text().toStdString(), txtDurata->text().toDouble());
			reloadList(serv.getAll());
			txtTitlu->setText("");
			txtDescriere->setText("");
			txtType->setText("");
			txtDurata->setText("");
		}
		catch (RepoException& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
		}
	}
	//adaugaButoane();
	
}
void ObiectGui::removeObiect() {
	try {
		serv.sterge_service(txtTitlu->text().toStdString());
		reloadList(serv.getAll());
		txtTitlu->setText("");
		txtDescriere->setText("");
		txtType->setText("");
		txtDurata->setText("");
	}
	catch (RepoException& ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
	}
}
void ObiectGui::reloadList(const std::vector<Obiect>& obiecte) {
	/*lst->clear();
	adaugaButoane();
	qDebug() <<"asdasdadsads"<< butoane.size();
	for (const auto& p : obiecte) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(p.getTitlu()));
		item->setData(Qt::UserRole, QString::fromStdString(p.getType()));
		if (p.getDurata() > 4) {
			item->setData(Qt::BackgroundRole, QBrush{ Qt::red, Qt::SolidPattern });
		}
		lst->addItem(item);

	}*/
	lst = new MyListModel{ obiecte };
	view->setModel(lst);
	view->setSelectionMode(QAbstractItemView::SingleSelection);

}
void ObiectGui::filtraredupatip() {
	reloadList(serv.filtrare_dupa_tip());
}
void ObiectGui::filtraredupadescriere() {
	reloadList(serv.filtrare_dupa_descriere());
}
void ObiectGui::connectSignalsSlots() {
	//cand se emite semnalul clicked de pe buton reincarc lista
	QObject::connect(btnsortare, &QPushButton::clicked, this, &ObiectGui::sortareObiect);
	QObject::connect(Undo, &QPushButton::clicked, this, &ObiectGui::UNDO);
	QObject::connect(btnadauga, &QPushButton::clicked, this, &ObiectGui::addObiect);
	QObject::connect(btnremove, &QPushButton::clicked, this, &ObiectGui::removeObiect);
	QObject::connect(btnupdatedupadescriere, &QPushButton::clicked, this, &ObiectGui::updateObiect);
	QObject::connect(btnupdatedupatip, &QPushButton::clicked, this, &ObiectGui::updateObiect);
	QObject::connect(btnupdatedupadurata, &QPushButton::clicked, this, &ObiectGui::updateObiect);
	
	QObject::connect(btnFilterByDescriere, &QPushButton::clicked, this, &ObiectGui::filtraredupadescriere);
	QObject::connect(btnFilterByTip, &QPushButton::clicked, this, &ObiectGui::filtraredupatip);
	QObject::connect(view, &QListView::pressed, [&]() {
		//auto sel = lst->selectedItems();
		qDebug() << "HERE!!!!!!!!!!\n";
		auto sel = view->selectionModel();
		if (sel->selectedRows().size()<0) {
			txtTitlu->setText("");
			txtDescriere->setText("");
			txtType->setText("");
			txtDurata->setText("");
		}
		else {
			auto selItem = sel->selectedRows().at(0);
			
			qDebug() << selItem;
			QAbstractItemModel* model = view->model();
			auto titlu = selItem.data(Qt::DisplayRole).toString();
			qDebug() << titlu;
			auto descriere = selItem.data(Qt::DisplayRole).toString();
			auto tip = selItem.data(Qt::UserRole).toString();
			auto durata = selItem.data(Qt::UserRole).toDouble();
			txtTitlu->setText(titlu);
			txtDescriere->setText(descriere);
			txtType->setText(tip);

			for (auto p : serv.getAll()) {
				if (p.getTitlu() == titlu.toStdString()) {
					txtDurata->setText(QString::number(p.getDurata()));
				}
			}
			
			
		}
	});
	QObject::connect(cos, &QPushButton::clicked, [&]() {
		//cosWindow = new QWidget;

		//cosWindow->show();
		qDebug() << "aici";
		auto danutz = new CosGui{ serv.getCos(),serv };
		danutz->show();
		reloadListCos(serv.get_all_cos());
		});
	QObject::connect(cos2, &QPushButton::clicked, [&]() {
		//cosWindow = new QWidget;

		//cosWindow->show();
		qDebug() << "aici";
		auto danutz = new Histograma{ serv };
		danutz->show();
		//reloadListCos(serv.get_all_cos());
		});

	QObject::connect(adaugacos, &QPushButton::clicked, [&]() {
	
			serv.add_wish_list(txtTitlu->text().toStdString());
		
		
		});

	QObject::connect(goleste, &QPushButton::clicked, [&]() {
		serv.goleste_cosul();
		reloadListCos(serv.get_all_cos());
		});

	QObject::connect(genereaza, &QPushButton::clicked, [&]() {
		serv.genereaza(textGenereaza->text().toInt());
		reloadListCos(serv.get_all_cos());
		});

	QObject::connect(exporta, &QPushButton::clicked, [&]() {
		serv.Export(textExporta->text().toStdString());
		QUrl fileUrl = QUrl::fromLocalFile(textExporta->text());
		QDesktopServices::openUrl(fileUrl);
		});
	
	
}
void ObiectGui::reloadListCos(const std::vector<Obiect>&obiecte) {
	tablou->clear();
	int coloumn = 0;
	int row = 0;
	//qDebug() << "asdasdadsads" << butoane.size();
	for (const auto& p : obiecte) {
		QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(p.getTitlu()));
		QTableWidgetItem* item1 = new QTableWidgetItem(QString::fromStdString(p.getDescriere()));
		qDebug() << p.getDescriere();
		QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(p.getType()));
		
		tablou->setItem(row,coloumn,item);
		coloumn++;
		tablou->setItem(row,coloumn,item1);
		coloumn++;
		tablou->setItem(row,coloumn,item2);
	
	
		//row++;
		
			row++;
			coloumn = 0;
		

	}

}

void ObiectGui::adaugaButoane( ) {
	qDebug() << "am ajuns aici";
	auto ob = serv.getAll();
	set<string >descrieri;
	for (const auto& obiect : ob) {
		descrieri.insert(obiect.getDescriere());
	}
	for (const auto& descriere : descrieri) {
		if (butoane.find(descriere) != butoane.end())
		{
			continue;
		}
		QPushButton* btn = new QPushButton(QString::fromStdString(descriere));
		lyBtnDy->addWidget(btn);
		std::map<std::string, vector<string>> m;
		
		butoane[descriere] = btn;
		QObject::connect(btn, &QPushButton::clicked, [this, btn, descriere,m]() {
			for (auto I : serv.creaza_map()) {
				if (I.first == descriere) {
					qDebug() << QString::number(I.second.size());
					QObject::disconnect(btn, &QPushButton::clicked, this, &ObiectGui::adaugaButoane);
					QMessageBox::information(nullptr, "Info", QString::number(I.second.size()));
					//delete btn;
					
				}
			}
		});
	
		
	}
	vector<string>obiecteRemove;
	for (const auto& pair : this->butoane) {
		vector<Obiect>::iterator it = std::find_if(ob.begin(), ob.end(), [&pair](const Obiect& obj) {
			return obj.getDescriere() == pair.first; // Assuming getKey() is a member function that returns the key of the object
			});
		if (it == ob.end()) {
			obiecteRemove.push_back(pair.first);
		}
	}
	for (const auto& obiect : obiecteRemove) {
		delete this->butoane[obiect];
		this->butoane.erase(obiect);
	}
}
