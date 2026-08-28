//============================================================================
// Name        : 1.cpp
// Author      : Priyanka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
using namespace std;

int main() {
	double Fahrenheit;
	string result;
	double Temp;
	int statusCode;

	cout << "Enter A Temperature :" ;
	cin >> Temp;

	if(Temp < 0){

		cout << "SENSOR_ERROR" << endl;
		statusCode = -1 ;
	}
	else if(Temp <= 29){
		cout << "Normal" << endl;
		statusCode = 0;
	}
	else if(Temp >= 30 && Temp <= 44){
		cout << "warning" << endl ;
		statusCode=1;
	}
	else if(Temp >= 45 && Temp <= 59){
		cout << "CRITICAL"<< endl ;
		statusCode =  2;
	}
	else{
		cout << "SHUTDOWN" << endl;
		statusCode = 3;
	}



	switch(statusCode){

	case -1:
		cout << "Sensor fault-checking wiring" << endl;
		break;
	case 0:
		cout << "No action required" << endl;
		break;
	case 1:
		cout << "Alert send to supervisor" << endl;
		break;
	case 2:
		cout << "Cooling system triggered" << endl;
		break;
	case 3:
		cout << "Emergency shutdown initiated" << endl;
		break;
	default:
		cout << "-------"<< endl;
		break;
	}

    result = Temp > 25 ? "Above Average" : "Below Average" ;
    cout << result << endl;

    Fahrenheit = (Temp * 9 / 5) + 32;
    cout << "fahrenheit : " << Fahrenheit << endl;

	return 0;
}
