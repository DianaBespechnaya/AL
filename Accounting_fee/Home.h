#include "Abstract.h"
#include "Map"
#include <fstream>

using namespace std;

map <string, int> services = {  { "Electricity", 37 },
								{ "HotWater", 40 },
								{ "ColdWater", 15 },
								{ "Repair", 20 } };

class Home : public Abstract {
private:
	int tenants;
	map <string, int> this_services;
	int bill;
	int paid;
public:
	Home(string num, int ten) : Abstract(num) { tenants = ten; };
	~Home() { this_services.clear(); };
	void InsertBill();
	void SetPaid(int);
	void InsertServices(string);
	friend ostream& operator<<(ostream&, const Home&);
	void SetTenants(int);
	void save();
	
};
ostream& operator<<(ostream& os, const Home& hm){
	os << "��� ����� " << hm.Name << endl << "\t���������� �������: " << hm.tenants << endl << "\t����: " << hm.paid << endl;
	return os;
}

void Home::InsertServices(string usl){
	this_services[usl] = services[usl];
}

void Home::InsertBill() {
	for (auto v : this_services) 
		bill += v.second*tenants;
	cout << "���� ���� ����� " << Name << " ���������� " << bill << endl;
}

void Home::SetPaid(int money) {
	paid += money;
	cout << "�� ������ ������ �� ������ ���� ����� " << Name << " ������� " << paid << endl;
}

void Home::SetTenants(int num) {
	tenants = num;
}

void Home::save() {
	ofstream fout("cppstudio.txt");
	fout << *this;
	fout.close();
}

