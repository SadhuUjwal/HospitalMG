#include "Hospital.h"
#include <sstream>
#include <fstream>
#include <iostream>
Hospital::Hospital(string name,int cap):
hospitalName(name),
fileName("records.csv"),
patientCapacity(cap),
totalPatients(0)
{

}


Hospital::~Hospital()
{
	Patient *pat = NULL;
	while (!Patients.empty())
	{
		pat = Patients.back();
		Patients.pop_back();
		delete pat;
		pat = NULL;
	}
}

void Hospital::admit(Patient *pat)
{
	Patients.push_back(pat);
	totalPatients++;
}
void Hospital::display(ePatient type)
{
	system("cls");
	cout << "Hospital: " << hospitalName << endl;
	cout << "Patient Capacity: " << patientCapacity <<"        Available Beds: "<<patientCapacity-totalPatients << endl;
	cout << "\nPatient Name | Spouse Name | Sex  |Patient Type| Unit / Appt.Date | Diagnosis" << endl;
	cout << "---------------------------------------------------------------------- " << endl;
	if (type == ePatientTypeAny)
	{
		for (vector<Patient* >::iterator it = Patients.begin(); it != Patients.end(); ++it)
			cout << (*it)->toString() << endl;
	}
	else if (type == ePatientOU)
	{
		for (vector<Patient* >::iterator it = Patients.begin(); it != Patients.end(); ++it)
			if (((*it)->getType() == ePatientFemaleOut) || ((*it)->getType() == ePatientMaleOut))
				cout << (*it)->toString() << endl;
	}
	else if (type == ePatientIN)
	{
		for (vector<Patient* >::iterator it = Patients.begin(); it != Patients.end(); ++it)
			if (((*it)->getType() == ePatientFemaleIn) || ((*it)->getType() == ePatientMaleIn))
				cout << (*it)->toString() << endl;
	}
	cout << endl;
}
void Hospital::readRecordsFile()
{
	fstream   myfile;
	string data;
	
	myfile.open(fileName.c_str());
	while (!myfile.eof())
	{
		{
			Patient *pat = NULL;
			getline(myfile, data);
			ePatient type = determinePatientType(data);
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
			admit(pat);
		}
	}
}
ePatient Hospital::determinePatientType(string data)
{
	ePatient type;
	string sType;
	stringstream ss(data);
	getline(ss, sType, ',');
	type = static_cast<ePatient>(atoi(sType.c_str()));
	return type;
}