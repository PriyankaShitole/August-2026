//============================================================================
// Name        : 2.cpp
// Author      : Priyanka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
using namespace std;

class Patient{
	int patientID;
	string name;
	int age;
	string ward;
	const string bloodGroup;

public:

	Patient(): patientID(0), name("Unknown"), age(0),ward("General"), bloodGroup("O+"){
		cout << "[Constructor] Default patient registered." << endl;


	}
	Patient(int id, const string& name):patientID(id), name(name), age(0),ward("General"), bloodGroup("O+"){
		cout << "[Constructor] Emergency: " << name << endl;

	}
	Patient(int id, const string& name, int age, const string& ward, const string& bg):patientID(id), name(name), age(age),ward(ward), bloodGroup(bg){
		cout << "[Constructor] Full admission: " << name << endl;

	}
	~Patient(){

		cout << "[Destructor] Patient " << name << " discharged." << endl;
	}
	void displayRecord()const{
		cout << "\nPatient Record:" << patientID << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Ward: " << ward << endl;
		cout << "Blood Group: " << bloodGroup << endl;



	}

	void transferWard(const string& newWard){
		cout << "Ward Transfer: " << name << " -> " << newWard << endl;
		ward = newWard;

	}


};

int main() {

    // 1. Full admission constructor
	Patient p1(101, "Priyanka", 22, "ICU", "B+");
	p1.displayRecord();

    // 2. Emergency admission constructor
	Patient p2(102, "Sanchita");

    // 3. Default constructor
	Patient p3;

	Patient* patients = new Patient[4];   //4 Patient objects तयार झाले.

	for(int i=0; i<4; i++){
		patients[i].displayRecord();
	}
	p2.transferWard("ICU");
	p2.displayRecord();

	delete[] patients;             //हे केल्यावर patients मधले 4 objects destroy होतील आणि त्यांचा destructor 4 वेळा call होईल.

	return 0;
}
