#include "Abstract.h"
#include "Map"
#include <fstream>

using namespace std;
extern vector <string> history;

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
	string getName() { return Name; }
	Home(){  }
	Home(string num, int ten) : Abstract(num) { 
	tenants = ten; paid = 0; bill = 0; };
	~Home() { this_services.clear(); };
	void InsertBill();
	void SetPaid(int);
	void InsertServices(string);
	void DeleteServices(string);
	friend ostream& operator<<(ostream&, const Home&);
	friend istream& operator>> (istream&, Home&);
	void SetTenants(int);
	void save();
	void read(string);
	int debt();
	map<string, int> getServices() { return this_services; }
	
};
ostream& operator<<(ostream& os, const Home& hm){
	os << hm.Name << endl << hm.tenants << endl << hm.paid << endl << hm.bill << endl;
	return os;
}

istream& operator>> (istream& is, Home& hm){
	is >> hm.Name >> hm.tenants >> hm.paid >> hm.bill;
	return is;
}

void Home::InsertServices(string usl){
	this_services[usl] = services[usl];
	string temp = "� ���� ����� " + Name + " ���������� ������ " + usl;
	history.push_back(temp);
}
void Home::DeleteServices(string usl){
	auto it = this_services.find(usl);
	this_services.erase(it);
	string temp = "� ���� ����� " + Name + " ��������� ������ " + usl;
	history.push_back(temp);
}
void Home::InsertBill() {
	for (auto v : this_services) 
		bill += v.second*tenants;
	cout << "���� ���� ����� " << Name << " ���������� " << bill << endl;
	string temp = "��������� ���� ��� ���� ����� " + Name + " � ������� " + to_string(bill);
	history.push_back(temp);
}

void Home::SetPaid(int money) {
	paid += money;
	cout << "�� ������ ������ �� ������ ���� ����� " << Name << " ������� " << paid << endl;
	string temp = "�� ������ ���� ����� " + Name + " ������� " + to_string(money) + " ������.";
	history.push_back(temp);
}

void Home::SetTenants(int num) {
	tenants = num;
	//string tt = "���������� ������� ���� ����� " + Name + " �������� �� " + to_string(num);
	//history.push_back(tt);
}

void Home::save() {
	ofstream fout("cppstudio.txt");
	fout << *this;
	fout.close();
}

void Home::read(string name) {
	ifstream fin("cppstudio.txt");
	fin >> *this;
	fin.close();
}

int Home::debt() {
	return bill - paid;
}
