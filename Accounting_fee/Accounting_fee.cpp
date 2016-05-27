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

	street.read();

	//for (string v : history) //������� ������
	//	cout << v << endl;

	int command;
	char buf[250], buf2[250];
	string temp1, temp3;
	int temp2;

	cout << "���������� � �������������� ������ ������� �������������.\n\n�������� ����� ����������� �������: \n\t1. �������� ������ ���� � ���� �����.\n\t2. �������� ���� �� ������� �����. \n\t3. �����������/���������� ������ ��� � ���������� ����.\n\t4. ��������� ���������� ������� � ���������� ����.\n\t5. ����������� ����� �� ������ �� �����.\n\t6. ��������� ������ �� ������ ����� �� �����. \n\t7. ����������� ���������.\n\t8. �������� ����� � ������������ �������.\n\t9. �������� ���� ����� �����. ��� ������ �� ��������� ������� 0.\n";
	
	try {
		cin >> command;
		if (command != 1 && command != 2 && command != 3 && command != 4 && command != 5 && command != 6 && command != 7 && command != 8 && command != 9 && command != 0) {
			throw "������ �������� ����� �������.";
		}
	}
	catch (char* str) {
		cout << str << endl;
		cout << "������� ��������� �������: ";
		command = -1;
	}
	if (command == -1) cin >> command;
	do {
		
		if (command == 1) {
			cout << "������� ����� ���� � ���������� �������: " << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			Home* temp = new Home(temp1, temp2);
			street.InsertHouse(temp);
		}
		if (command == 2) {
			cout << "������� ����� ����: " << endl;
			cin >> temp1;
			try { street.DeleteHouse(temp1); }
			catch (char* str) { cout << str<<endl; }
		}
		if (command == 3) {
			cout << "��� ���������� ������ ������� 1_����� ����_�������� ������,\n ��� �������� - 0_����� ����_�������� ������.\n\t������ �����: HotWater, ColdWater, Electricity, Repair.\n" << endl;
			scanf("%d %s %s", &temp2, &buf, &buf2);
			temp1 = (const char*)buf;
			temp3 = (const char*)buf2;
			if (temp2 == 0)
			{
				try { street[temp1].DeleteServices(temp3); }
				catch (char* str) { cout << str<<endl; }
			}
			else
			{
				try { street[temp1].InsertServices(temp3); }
				catch (char* str) { cout << str << endl; }
			}
		}
		if (command == 4) {
			cout << "������� ����� ���� � ����� ���������� �������:" << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			try { street[temp1].SetTenants(temp2); }
			catch (char* str) {cout << str << endl;}
		}
		if (command == 5) {
			street.InsertAllBills();
		}
		if (command == 6) {
			cout << "������� ����� ���� � ��������� �����: " << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			try { street[temp1].SetPaid(temp2); }
			catch (char* str) {cout << str << endl;}
		}
		if (command == 7) {
			try { street.SearchDebtors(); }
			catch (char* str) { cout << str << endl; }
		}
		if (command == 8) {
			cout << "������� �������� ������: " << endl;
			scanf("%s", &buf);
			temp1 = (const char*)buf;
			try { street.SearchService(temp1); }
			catch (char* str) { cout << str << endl; }
		}
		if (command == 9) {
			try { cout << street << endl; }
			catch (char* str) { cout << str << endl; }
		}
		if (command == 0)
			exit(0);
			
		try { street.save(); }
		catch (char*str) { cout << str << endl; }
		cout << "������� ��������� �������: ";
		try { cin >> command;
		if (command != 1 && command != 2 && command != 3 && command != 4 && command != 5 && command != 6 && command != 7 &&command != 8 && command != 9 && command != 0) {
			throw "������ �������� ����� �������.";
		}
		}
		catch(char* str) { cout << str << endl;
		cout << "������� ��������� �������: ";
		command = -1;
		}
		if (command == -1) cin >> command;
	} while (command != 0);

	system("pause");
	return 0;
}

