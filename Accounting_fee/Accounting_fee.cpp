// Accounting_fee.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "Street.h"
#include "clocale"
#include <memory>
#include <stdio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	Street street("����������");
	Home first("3/5", 5);
	Home second("2", 7);
	Home third("44", 2);
	Home four("5", 3);
	
	street.InsertHouse(first);
	street.InsertHouse(second);
	street.InsertHouse(third);
	street.InsertHouse(four);

	
	//test.DeleteHouse("3/5");
	//cout << test << endl;

	//test[four.getName()].InsertServices("Repair");
	//test[third.getName()].InsertServices("Repair");
	//test[four.getName()].InsertServices("Electricity");
	//test[four.getName()].DeleteServices("Repair");
	//four.InsertServices("ColdWater");
	//second.InsertServices("ColdWater");
	//test.InsertAllBills();
	//second.SetPaid(700);

	//test.save();

	//test.SearchService("Repair");
	//test.SearchDebtors();
	//cout << test << endl;
	//second.save();
	//four.read("cppstudio.txt");
	//cout << four;

	//for (string v : history)
	//	cout << v << endl;

	int command;
	char buf[250], buf2[250];
	string temp1, temp3;
	int temp2;
	
	cout << "�������� ����� ����������� �������: \n\t1. �������� ������ ���� � ���� �����.\n\t2. �������� ���� �� ������� �����. \n\t3. �����������/���������� ������ ��� � ���������� ����.\n\t4. ��������� ���������� ������� � ���������� ����.\n\t5. ����������� ����� �� ������ �� �����.\n\t6. ��������� ������ �� ������ ����� �� �����. \n\t7. ����������� ���������.\n\t8. �������� ����� � ������������ �������.\n\t9. �������� ���� ����� �����. ��� ������ �� ��������� ������� 0.\n";
	cin >> command;

	do {
		switch (command) {
		case 1:
			cout << "������� ����� ���� � ���������� �������: " << endl;
			scanf("%s %d", &temp1, &temp2);		
			street.InsertHouse(Home("9", 7));
			break;
		case 2:
			cout << "������� ����� ����: " << endl;
			cin >> temp1;
			street.DeleteHouse(temp1);
			break;
		case 3:
			cout << "��� ���������� ������ ������� 1_����� ����_��������� ������,\n ��� �������� - 0_����� ����_�������� ������.\n\t������ �����: HotWater, ColdWater, Electricity, Repair.\n" << endl;
			scanf("%d %s %s", &temp2, &buf, &buf2);
			temp1 = (const char*)buf;
			temp3 = (const char*)buf2;
			if (temp2 == 0) street[temp1].DeleteServices(temp3);
			else street[temp1].InsertServices(temp3);
			break;
		case 4:
			cout << "������� ����� ���� � ����� ���������� �������:" << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			street[temp1].SetTenants(temp2);
			break;
		case 5:
			street.InsertAllBills();
			break;
		case 6:
			cout << "������� ����� ���� � ��������� �����: " << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			street[temp1].SetPaid(temp2);
			break;
		case 7:
			street.SearchDebtors();
			break;
		case 8:
			cout << "������� �������� ������: " << endl;
			scanf("%s", &buf);
			temp1 = (const char*)buf;
			street.SearchService(temp1);
			break;
		case 9:
			cout << street << endl;
			break;
		case 0:
			//exit(0);
			break;
		}
		street.save();
		cin >> command;
	} while (command != 0);
	
	
	system("pause");
	return 0;
}

