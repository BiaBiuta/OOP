#include"wishlist.h"
#include<fstream>
#include<algorithm>
#include<random>
#include <chrono> 
#include <qdebug.h> 
vector<Obiect>wish_list::get_allcos() {
	return cos;
}
void wish_list::goleste_cos()  {
	this->cos.clear();
	notify();
}
void wish_list::add(Obiect& ob) {
	this->cos.push_back(ob);
	notify();
}
const vector<Obiect>& wish_list::getLista() const {
	return cos;
}
void wish_list::genereaza(int x, vector<Obiect>v) {
	
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(v.begin(), v.end(), default_random_engine(seed));
	for (int i = 0; i < x && !v.empty(); i++)
	{
		this->add(v.back());
		v.pop_back();
	}
	qDebug() << "eu";
	notify();
}
void wish_list::Export(string nume_fisier) {
	ofstream fout(nume_fisier);
	fout << "<html>";
	fout << "<style> table, th, td {border:1px solid black} body{background-color: #E6E6FA;} </style>";
	fout << "<body>";
	fout << "<table><tr><th>titlu</th> <th>descriere</th> <th>tip</th> <th>durata </th>";
	for (auto& x : this->cos)
	{
		fout << "<tr><td>" << x.getTitlu() << "<td>" << x.getDescriere() << "</td><td>" << x.getType()
			<< "</td><td>" << x.getDurata() << "</td><td>";
	}
	fout << "</table></body>";
	fout << "<html>";
}