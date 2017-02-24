#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include "Hospital.h"
using namespace std;

int main()
{
	char userTyped = -1;
	Hospital *hosp;
	while (1)
	{
		cout << "\tHospital Mangament system" << endl;
		cout << "\t\nHospital Name: empty_Database" << endl;
		cout << "\n\t1 - Create Hospital" << endl;
		cout << "\t0 - Exit" << endl;
		cin >> userTyped;
		if (userTyped == '1')
		{
			string name;
			int cap;
			int chose = -1;
			system("cls");
			cout << "New Hospital name: " << endl;
			cin >> name;
			system("cls");
			cout << "New Hospital capacity: " << endl;
			cin >> cap;
			hosp = new Hospital(name, cap);
			system("cls");
			hosp->readRecordsFile();
			while (1)
			{
				
				cout << " 1 -  Display all Patients " << endl;
				cout << " 2 -  Display all inpatients " << endl;
				cout << " 3 -  Display all outpatients " << endl;
				cout << " 4 -  Add New Patient" << endl;
				cout << " 0 - Exit \n" << endl;
				cin >> chose;
				switch (chose)
				{
				case 1:
					hosp->display(ePatientTypeAny);
					break;
				case 2:
					hosp->display(ePatientIN);
					
					break;
				case 3:
					hosp->display(ePatientOU);
					
					break;
				case 4:
				{	int patTyp;
				string data = "", tmp = "";
				ePatient type;
				system("cls");
				cout << "Add new Patient " << endl;
				cout << "1 - FemaleIn \n2 - FemaleOut\n3 - MaleIn\n4 - MaleOut" << endl;
				cin >> patTyp;
				switch (patTyp)
				{
				case 1:
					data += "9,";
					type = ePatientFemaleIn;
					break;
				case 2:
					data += "10,";
					type = ePatientFemaleOut;

					break;
				case 3:
					data += "5,";
					type = ePatientMaleIn;
					break;
				case 4:
					data += "6,";
					type = ePatientMaleOut;
					break;
				}

				cout << "Name: ";
				cin >> tmp;
				data += tmp;
				data += ",";
				cout << "SSN: ";
				cin >> tmp;
				data += tmp;
				data += ",";
				cout << "Insurance name: ";
				cin >> tmp;
				data += tmp;
				data += ",";
				cout << "Other: ";
				cin >> tmp;
				data += tmp;
				data += ",";
				cout << "Age: ";
				cin >> tmp;
				data += tmp;
				data += ",";
				cout << "Spouse Name: ";
				cin >> tmp;
				data += tmp;
				data += ",";
				cout << "Diagnosis: ";
				cin >> tmp;
				data += tmp;
				data += ",";
				cout << "Unit/Appt. Date: ";
				cin >> tmp;
				data += tmp;
				Patient *pat = NULL;
				switch (type)
				{
				case ePatientFemaleIn:
					pat = new FemaleIn(data, type);
					break;
				case ePatientFemaleOut:
					pat = new FemaleOut(data, type);
					break;
				case ePatientMaleIn:
					pat = new MaleIn(data, type);
					break;
				case ePatientMaleOut:
					pat = new MaleOut(data, type);
					break;
				}
				hosp->admit(pat);
				break; }
					case 0:
					delete hosp;
					hosp = NULL;
					exit(0);
					//not needed
					break;
				}
			}
	
		}
		else if (userTyped == '0')
		{
			exit(0);
		}
		else
		{
			cerr << "Wrong option please chose correct one" << endl;
		}
		Sleep(1);
		system("cls");
	}
	return 0;
}