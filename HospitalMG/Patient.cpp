#include "Patient.h"
#include <sstream>
MaleIn::MaleIn(string data, ePatient type)
{
	patientType = type;
	parse(data);
}

string MaleIn::toString()
{
	string display = "";
	display += name;
	display += " | ";
	display += spouseName;
	display +=  "  |   Male | Inpatient | ";
	display += roomNumber;
	display += " | ";
	display += diagnosis;
	return display;
}

void MaleIn::parse(string data)
{
	string tmp;
	stringstream ss(data);
	getline(ss, tmp, ',');
	getline(ss, name, ',');
	getline(ss, SSN, ',');
	getline(ss, insuranceName, ',');
	getline(ss, maleData, ',');
	getline(ss, age, ',');
	getline(ss, spouseName, ',');
	getline(ss, diagnosis, ',');
	getline(ss, roomNumber);
}

void MaleIn::enterPatientData(string data)
{
	parse(data);
}
ePatient MaleIn::getType()
{
	return patientType;
}

MaleOut::MaleOut(string data, ePatient type)
{
	patientType = type;
	parse(data);
}
string MaleOut::toString()
{
	string display = "";
	display += name;
	display += " | ";
	display += spouseName;
	display += "|  Male | Outpatient | ";
	display += appointmentDate;
	display += " | ";
	display += diagnosis;
	return display;
}

void MaleOut::parse(string data)
{
	string tmp;
	stringstream ss(data);
	getline(ss, tmp, ',');
	getline(ss, name, ',');
	getline(ss, SSN, ',');
	getline(ss, insuranceName, ',');
	getline(ss, maleData, ',');
	getline(ss, age, ',');
	getline(ss, spouseName, ',');
	getline(ss, diagnosis, ',');
	getline(ss, appointmentDate);

}

void MaleOut::enterPatientData(string data)
{
	parse(data);
}
ePatient MaleOut::getType()
{
	return patientType;
}

FemaleIn::FemaleIn(string data, ePatient type)
{
	patientType = type;
	parse(data);
}
string FemaleIn::toString()
{
	string display = "";
	display += name;
	display += " | ";
	display += spouseName;
	display += "  |  Female  |  Inpatient |   ";
	display += roomNumber;
	display += "  |  ";
	display += diagnosis;
	return display;
}

void FemaleIn::parse(string data)
{
	string tmp;
	stringstream ss(data);
	getline(ss, tmp, ',');
	getline(ss, name, ',');
	getline(ss, SSN, ',');
	getline(ss, insuranceName, ',');
	getline(ss, femaleData, ',');
	getline(ss, age, ',');
	getline(ss, spouseName, ',');
	getline(ss, diagnosis, ',');
	getline(ss, roomNumber);
}

void FemaleIn::enterPatientData(string data)
{
	parse(data);
}
ePatient FemaleIn::getType()
{
	return patientType;
}
FemaleOut::FemaleOut(string data, ePatient type)
{
	patientType = type;
	parse(data);
}
string FemaleOut::toString()
{
	string display = "";
	display += name;
	display += " | ";
	display += spouseName;
	display += " | Female  | Outpatient |  ";
	display += appointmentDate;
	display += "  | ";
	display += diagnosis;
	return display;
}

void FemaleOut::parse(string data)
{
	string tmp;
	stringstream ss(data);
	getline(ss, tmp, ',');
	getline(ss, name, ',');
	getline(ss, SSN, ',');
	getline(ss, insuranceName, ',');
	getline(ss, femaleData, ',');
	getline(ss, age, ',');
	getline(ss, spouseName, ',');
	getline(ss, diagnosis, ',');
	getline(ss, appointmentDate);
}

void FemaleOut::enterPatientData(string data)
{
	parse(data);
}
ePatient FemaleOut::getType()
{
	return patientType;
}