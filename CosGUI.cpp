#include "CosGUI.h"
#include<QtWidgets/QFormLayout>
#include<QtWidgets/QLineEdit>
void CosGui::initGui() {
	setLayout(lymain);
	lymain->addWidget(tabview);
	adauga = new QPushButton("adauga");
	lymain->addWidget(adauga);
	genereaza = new QPushButton("genereaza");
	lymain->addWidget(genereaza);
	sterge = new QPushButton("goleste");
	lymain->addWidget(sterge);
	exporta = new QPushButton("exporta");
	lymain->addWidget(exporta);
	QWidget* widDetalii = new QWidget;
	QFormLayout* formLdetalii = new QFormLayout;
	widDetalii->setLayout(formLdetalii);
	numar = new QLineEdit;
	formLdetalii->addRow(new QLabel("numar"), numar);
	lymain->addWidget(widDetalii);
	//show();
	qDebug() << "aici2";
}
void CosGui::reloadList1( const vector<Obiect>& vec) {
	//lst->clear();
	//int coloumn = 0;
	//int row = 0;
	////qDebug() << "asdasdadsads" << butoane.size();
	//for (const auto& p : vec) {
	//	QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(p.getTitlu()));
	//	QTableWidgetItem* item1 = new QTableWidgetItem(QString::fromStdString(p.getDescriere()));
	//	qDebug() << p.getDescriere();
	//	QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(p.getType()));

	//	lst->setItem(row, coloumn, item);
	//	coloumn++;
	//	lst->setItem(row, coloumn, item1);
	//	coloumn++;
	//	lst->setItem(row, coloumn, item2);
	//}
	lst = new MyTableModel{ vec };
	tabview->setModel(lst);
	//tabview->setSelectionModel(QAbstractItemView::ExtendedSelection);
}
void CosGui::connection() {
	//QObject::connect(adauga, &QPushButton::clicked, [&]() {

	//reloadList1(cos.add())


	//	});

	QObject::connect(sterge, &QPushButton::clicked, [&]() {
		cos.goleste_cos();
		reloadList1(cos.getLista());
		});

	QObject::connect(genereaza, &QPushButton::clicked, [&]() {
		qDebug() << "aici";
		cos.genereaza(numar->text().toInt(),serv.getAll());
		qDebug() << numar->text().toInt();
		reloadList1(cos.getLista());
		numar->setText("");
		});

	//QObject::connect(exporta, &QPushButton::clicked, [&]() {
	//	serv.Export(textExporta->text().toStdString());
	//	QUrl fileUrl = QUrl::fromLocalFile(textExporta->text());
	//	QDesktopServices::openUrl(fileUrl);
	//	});
}