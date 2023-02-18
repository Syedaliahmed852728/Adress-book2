
#include <iostream>
#include<iomanip>
#include<string>
#include<windows.h>
using namespace std;

class personType {
	string firstName;
	string lastName;
public:
	personType(string first,string last):firstName(first),lastName(last){}
	personType() {
		this->firstName = " ";
		this->lastName = " ";
	}
	string setfirstName();
	string setlastName();
	string getFirstName();
	string getLastName();
	string getName();
};
string personType::getFirstName() {
	return firstName;
}
string personType::getLastName() {
	return lastName;
}
string personType::setfirstName() {
	cout << "enter the first Name" << endl;
	cin >> firstName;
	return firstName;
}
string personType::setlastName() {
	cout << "enter the last Name" << endl;
	cin >> lastName;
	return lastName;
}
string personType::getName() {
	return firstName + ' ' +  lastName;
}


class AdressType {
	string streetAdress;
	string city;
	long int zip;
public:
	AdressType(string stAdress,string City,long int zipCode):
		streetAdress(stAdress),city(City),zip(zipCode){}
	AdressType() {
		this->streetAdress = " ";
		this->city = " ";
		this->zip = 0000;
	}
	string setStAdress();
	string setCity();
	long int setZip();
	string getStAdress();
	string getCity();
	long int getZip();
};
string AdressType::setStAdress() {
	cout << "enter the Adress" << endl;
	cin >> streetAdress;
	return streetAdress;
}
string AdressType::setCity() {
	cout << "enter the city" << endl;
	cin >> city;
	return city;
}

long int AdressType::setZip() {
	cout << "enter the zip code" << endl;
	cin >> zip;
	return zip;
}

string AdressType::getStAdress() {
	return streetAdress;
}
string AdressType::getCity() {
	return city;
}
long int AdressType::getZip() {
	return zip;
}


class dateType {
	int day;
	int month;
	int year;
public:
	dateType(int dd, int mm, int yy) :day(dd), month(mm), year(yy) {}
	dateType() {
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
	int setDay();
	int setmonth();
	int setYear();
	int getDay();
	int getmonth();
	int getYear();

	string getDOB();
};
int dateType::getDay() {
	return day;
}
int dateType::getmonth() {
	return month;
}int dateType::getYear() {
	return year;
}
int dateType::setDay() {
	cout << "enter the day of birthDay" << endl;
	cin >> day;
	return day;
}
int dateType::setmonth() {
	cout << "enter the month of birthday" << endl;
	cin >> month;
	return month;
}
int dateType::setYear() {
	cout << "enter the year of birthday" << endl;
	cin >> year;
	return  year;
}
string dateType::getDOB() {
	return to_string(day) + '/' + to_string(month) + '/' + to_string(year);
	cout << endl;
}
class association {
	string *name;
	string father;
	string *friends;
	int frSize;
	string* brothers;
	int brSize;
	string  *bussinessAss;
	int busSize;
public:
	association(string nn,int a,int b,int c):father(nn),frSize(a),brSize(b),busSize(c) {}
	association() {
		friends = new string[20];
		brothers = new string[20];
		bussinessAss = new string[20];
		frSize = 0;
		brSize = 0;
		busSize = 0;
	}
	void setData();
	void dipData();
};
void association::setData() {
	cout << "enter father name : " << endl;
	cin >> father;
	cout << "enter the number brothers" << endl;
	cin >> brSize;
	int i = 0;
	while (i != brSize) {
		cout << "enter the name of "<<i + 1 <<" brother" << endl;
		cin >> brothers[i];
		i++;
	}
	cout << "enter the number of close friends" << endl;
	cin >> frSize;
	for (int i = 0; i < frSize; i++) {
		cout << "enter the name of "<< i + 1 << " frineds" << endl;
		cin >> friends[i];
	}
	cout << "enter the number of bussiness associates" << endl;
	cin >> busSize;
	for (int i = 0; i < busSize; i++) {
		cout << "enter the name of "<< i+1<< " bussiness associate" << endl;
		cin >> bussinessAss[i];
	}
}
void association::dipData() {
	cout << "father Name : " << father << endl;
	cout << "brothers Names :" << endl;
	for (int i = 0; i < brSize; i++) {
		cout << i << ". " << brothers[i] << endl;
	}
	cout << "friends Names" << " " << endl;
	for (int i = 0; i < frSize; i++) {
		cout << i << ". " << friends[i] << endl;
	}
	cout << "bussiness Associates Names : " << endl;
	for (int i = 0; i < busSize; i++) {
		cout << i << ". " << bussinessAss[i] << endl;
	}
}
class extPersonType :public personType, public AdressType, public dateType,public association {
	 int familyMembers;
	 int friends;
	 int bussinessAssociate;
	 string associate;
	long intPhNumber;
public:
	extPersonType() {
		personType();
		AdressType();
		dateType();
		intPhNumber = 00000000;
		associate = " ";
		familyMembers = 0;
		friends = 0;
		bussinessAssociate = 0;
	}
	void setInfo();
	void getInfo();
	void getPerInfo();

};

void extPersonType::getPerInfo() {
	dipData();
}
void extPersonType::setInfo() {
	setfirstName();
	setlastName();
	setStAdress();
	setCity();
	setZip();
	setDay();
	setmonth();
	setYear();
	cout << "enter the association" << endl;
	cin >> associate;
	cout << "personal information : " << endl;
	setData();

	
}
void extPersonType::getInfo() {
	cout << "name:- " << getName() << endl;
	cout << "Adress :- " << getStAdress() << endl;
	cout << "city:- " << getCity() << endl;
	cout << "zip:- " << getZip() << endl;
	cout << "date of birth:- " << getDOB() << endl;
}
class AdressBookType :public extPersonType {
	extPersonType* arr;
	int n;
public:
	AdressBookType() {
		extPersonType();
		arr = new extPersonType[500];
	}
	void setAdress();
	void getAdress();
	void sort();
	int search(string);
	void BirthPrint();
	void perInfo(int index);
};
void AdressBookType::perInfo(int index) {
	arr[index].getPerInfo();
}
void AdressBookType:: BirthPrint() { 
		SYSTEMTIME currTime;
		GetSystemTime(&currTime);
		for (int i = 0; i < n; i++) {
			if (currTime.wMonth == arr[i].getmonth()) {
				arr[i].getInfo();
				cout << endl;
		}
	}
}
void AdressBookType::setAdress() {
	cout << "enter the number of person you want to store the data of" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "enter the data of" << i + 1 << "person" << endl;
		arr[i].setInfo();
		cout << endl;
	}
}
void AdressBookType::getAdress() {
	for (int i = 0; i < n; i++) {
		cout << "Record of " << i + 1 << "student" << endl;
		arr[i].getInfo();
		cout << endl;
	}
}
void AdressBookType::sort() {
	int k = 0;
	for (int i = 0; i < n; i++) {
		k = 0;
		for (int j = i + 1; j < n; j++) {
			while (arr[i].getName()[k] == arr[j].getName()[k]) {
				k++;
				if (arr[i].getName()[k] > arr[j].getName()[k]) {

					swap(arr[i], arr[j]);
				}
			}
			
			
		}
	}
}
int AdressBookType::search( string Name) {
	for (int i = 0; i < n; i++) {
		if (arr[i].getLastName() == Name) {
			arr[i].getInfo();
			return i;
		}
	}
	cout << "not found" << endl;
	return -1;
}
void menu() {
	cout << "1.to store the data" << endl;
	cout << "2.to diplay the data" << endl;
	cout << "3.to sort the data" << endl;
	cout << "4.to search the data" << endl;
	cout << "5.to display the data of people having the birthday" << endl;
	cout << "7.to display the all detailed and personal information" << endl;
	cout << "6.to exit" << endl;
}
int main()
{
	AdressBookType A;
	char option;
	string name;
	do {
		cout << "chose the option" << endl;
		menu();
		cin >> option;
		switch (option) {
		case '1':
			A.setAdress();
			break;
		case '2':
			A.getAdress();
			break;
		case '3':
			A.sort();
			break;
		case '4':
			cout<<"enter the last name of person you want to get the record of"<<endl;
			cin >> name;
			A.search(name);
			break;
		case'5':
			A.BirthPrint();
			break;
		case'6':
			exit(0);
		case '7':
		{cout << "enter the last name of person you want to get the detail of" << endl;
		cin >> name;
		int found = A.search(name);
		if (found != -1) {
			A.perInfo(found);
		}
		else {
			cout << "record not found" << endl;
		}
		}
			break;
		default:
			cout << "chose the correct option" << endl;
		}
	} while (true);
}

