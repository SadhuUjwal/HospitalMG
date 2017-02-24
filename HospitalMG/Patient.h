#pragma once
#include <string>
using namespace std;
enum ePatient
{
	ePatientFemaleIn = 9,
	ePatientFemaleOut = 10,
	ePatientMaleIn = 5,
	ePatientMaleOut = 6,
	ePatientIN = 1,
	ePatientOU = 2,
	ePatientTypeAny = 0

};

class Patient
{
public:
	
	virtual ~Patient(){};
	virtual string toString() = 0;
	virtual void enterPatientData(string data) = 0;
	virtual ePatient getType() = 0;
protected:
	virtual	void parse(string data)=0;
	string name;
	string SSN;
	string insuranceName;
	string age;
	string spouseName;
	string diagnosis;
	ePatient patientType;
};

///###################################
class Female : virtual public Patient
{
protected:
	string femaleData;
};
class Male : virtual public Patient
{
protected:
	string maleData;
};
class Inpatient : virtual public Patient
{

protected:
	string roomNumber;
};
class Outpatient : virtual public Patient
{

protected:
	string appointmentDate;
};


//###########################################


class FemaleOut : public Female, public Outpatient
{
public:
	FemaleOut(string data, ePatient type);
	string toString();

	void enterPatientData(string data);
	ePatient getType();
protected:
	void parse(string data);
};

class FemaleIn : public Female, public Inpatient
{
public:
	FemaleIn(string data, ePatient type);
	string toString();
	void enterPatientData(string data);
	ePatient getType();
protected:
	void parse(string data);
};



class MaleOut : public Male, public Outpatient
{
public:
	MaleOut(string data, ePatient type);
	string toString();
	void enterPatientData(string data);
	ePatient getType();
protected:
	void parse(string data);
};

class MaleIn : public Male, public Inpatient
{
public:
	MaleIn(string data, ePatient type);
	string toString();
	void enterPatientData(string data);
	ePatient getType();
protected:
	void parse(string data);
	
};
