// Accounting_fee.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "Street.h"
#include "clocale"
#include <memory>


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	Street test("������");
	Home first("3/5", 5);
	Home second("2", 7);
	Home third("44", 2);
	Home four("5", 3);
	
	test.InsertHouse(first);
	test.InsertHouse(second);
	test.InsertHouse(third);
	test.InsertHouse(four);

	cout << test << endl;
	test.DeleteHouse("3/5");
	//cout << test << endl;

	test[four.getName()].InsertServices("Repair");
	//four.InsertServices("ColdWater");
	//second.InsertServices("ColdWater");
	test.InsertAllBills();
	second.SetPaid(700);

	test.save();

	//test.SearchService("Repair");
	//test.SearchDebtors();
	//cout << test << endl;
	//second.save();
	//four.read("cppstudio.txt");
	//cout << four;

	for (string v : history)
		cout << v << endl;

	int command;
	string temp1;
	int temp2;
	Street street("����������");
	cout << "�������� ����� ����������� �������: \n\t1. �������� ������ ���� � ���� �����.\n\t2. �������� ���� �� ������� �����. \n\t3. �����������/���������� ������ ��� � ���������� ����.\n\t4. ��������� ���������� ������� � ���������� ����.\n\t5. ����������� ����� �� ������ �� �����.\n\t6. ��������� ������ �� ������ ����� �� �����. \n\t7. ����������� ���������.\n\t8. �������� ����� � ������������ �������.\n\t ��� ������ �� ��������� ������� 0.\n";
	
	cin >> command;

	shared_ptr<Home> temp;
	
	
	do {
		switch (command) {
		case 1:
			cout << "������� ����� ���� � ���������� �������: " << endl;
			//scanf("%s %d", &temp1, &temp2);		
			
			//street.InsertHouse(*temp);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 0:
			//exit(0);
			break;
		cin >> command;
		}
	} while (command != 0);
	
	cout << street;
	system("pause");
	return 0;
}

