#pragma once
#include <vector>
#include "Patient.h"


class Hospital
{
public:
	Hospital(string name,int cap);
	~Hospital();
	void readRecordsFile();
	void display(ePatient type);
	void admit(Patient *pat);

private:
	ePatient determinePatientType(string data);
	vector<Patient *> Patients;
	string hospitalName;
	string fileName;
	int patientCapacity;
	int totalPatients;
};

