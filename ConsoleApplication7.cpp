#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

// ���� �����������
class User {
public:
	string Login;
	string Password;
	string Role;
	User() {

	}
	// ����������� ��� �����������
	User(string Login, string Password, string Role) {
		this->Login = Login;
		this->Password = Password;
		this->Role = Role;
	}
};

// ���� ������ ��� ����������
class Person {
public:
	string Name;
	string Birth;
	string Pay;
	string Phone;
	Person() {

	}
	// ����������� ��� �����������
	Person(string Name, string Birth, string Pay, string Phone) {
		this->Name = Name;
		this->Birth = Birth;
		this->Pay = Pay;
		this->Phone = Phone;
	}
};

// ���������� ���������� � ������
list<Person*> GetPeople() {
	// ��������� ������ ��� ����� �� ���������� �����
	list<Person*> PL;
	fstream F("Info.txt");
	string Temp1;
	string Temp2;
	string Temp3;
	string Temp4;
	// ���������� � 4 ����, ��������� ��������� �� ������� �� ��������� � ������
	while (getline(F, Temp1) && getline(F, Temp2) && getline(F, Temp3) && getline(F, Temp4)) {
		Person* P = new Person(Temp1, Temp2, Temp3, Temp4);
		PL.push_back(P);
	}
	return PL;
}

// ���������� ������������ � ������
list<User*> GetUsers() {
	// ��������� ������ ��� ������������ �� ���������� �����
	list<User*> UL;
	fstream F("Users.txt");
	string Temp1;
	string Temp2; 
	string Temp3;
	// ���������� � 3 ����, ��������� ��������� �� ������� �� ��������� � ������
	while (getline(F, Temp1) && getline(F, Temp2) && getline(F, Temp3)) {
		User* U = new User(Temp1, Temp2, Temp3);
		UL.push_back(U);
	}
	return UL;
}

// ����� �񳺿 ���������� ��� �����
void Display(list<Person*>& PL) {
	int j = 1;
	cout << "N\tNAME\t\tYEAR\tPAY\tPHONE" << endl;
	// ������ ������ �� �����
	for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
		cout << j << "\t" << (*i)->Name << "\t" << (*i)->Birth << "\t" << (*i)->Pay << "\t" << (*i)->Phone << endl;
		j++;
	}
}

// ���������� ���������� �� ���� � �������� ���������
void SortByName(list<Person*>& TPL) {
	list<Person*> PL = TPL;
	for (int i = 0; i != PL.size() - 1; i++) {
		for (list<Person*>::iterator j = ++PL.begin(); j != PL.end(); j++) {
			list<Person*>::iterator t = j;
			t--;
			if ((*t)->Name > (*j)->Name) {
				// Swap ��������� �� �������
				Person* P = *j;
				*j = *t;
				*t = P;
			}
		}
	}
	Display(PL);
}

// ���������� ���������� �� ���� ���������� � �������� ���������
void SortByBirth(list<Person*>& TPL) {
	list<Person*> PL = TPL;
	for (int i = 0; i != PL.size() - 1; i++) {
		for (list<Person*>::iterator j = ++PL.begin(); j != PL.end(); j++) {
			list<Person*>::iterator t = j;
			t--;
			if ((*t)->Birth > (*j)->Birth) {
				// Swap ��������� �� �������
				Person* P = *j;
				*j = *t;
				*t = P;
			}
		}
	}
	Display(PL);
}

// ���������� ���������� �� ���� � �������� ���������
void SortByPay(list<Person*>& TPL) {
	list<Person*> PL = TPL;
	for (int i = 0; i != PL.size() - 1; i++) {
		for (list<Person*>::iterator j = ++PL.begin(); j != PL.end(); j++) {
			list<Person*>::iterator t = j;
			t--;
			int T1 = atoi((*t)->Pay.c_str());
			int T2 = atoi((*j)->Pay.c_str());
			if (T1 > T2) {
				// Swap ��������� �� �������
				Person* P = *j;
				*j = *t;
				*t = P;
			}
		}
	}
	Display(PL);
}

// ����� �� ���� � �������� ���������
void SearchByName(list<Person*>& PL, string T) {
	int j = 1;
	int Count = 0;
	for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
		if ((*i)->Name == T) {
			Count++;
		}
	}
	if (Count == 0) {
		cout << "Not found" << endl;
	}
	else {
		cout << "N\tNAME\t\tYEAR\tPAY\tPHONE" << endl;
		for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
			if ((*i)->Name == T) {
				cout << j << "\t" << (*i)->Name << "\t" << (*i)->Birth << "\t" << (*i)->Pay << "\t" << (*i)->Phone << endl;
				j++;
			}
		}
	}
}

// ����� �� ���� ���������� � �������� ���������
void SearchByBirth(list<Person*>& PL, string T) {
	int j = 1;
	int Count = 0;
	for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
		if ((*i)->Birth == T) {
			Count++;
		}
	}
	if (Count == 0) {
		cout << "Not found" << endl;
	}
	else {
		cout << "N\tNAME\t\tYEAR\tPAY\tPHONE" << endl;
		for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
			if ((*i)->Birth == T) {
				cout << j << "\t" << (*i)->Name << "\t" << (*i)->Birth << "\t" << (*i)->Pay << "\t" << (*i)->Phone << endl;
				j++;
			}
		}
	}
}

// ����� �� ���� � �������� ���������
void SearchByPay(list<Person*>& PL, string T) {
	int j = 1;
	int Count = 0;
	for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
		if ((*i)->Pay == T) {
			Count++;
		}
	}
	if (Count == 0) {
		cout << "Not found" << endl;
	}
	else {
		cout << "N\tNAME\t\tYEAR\tPAY\tPHONE" << endl;
		for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
			if ((*i)->Pay == T) {
				cout << j << "\t" << (*i)->Name << "\t" << (*i)->Birth << "\t" << (*i)->Pay << "\t" << (*i)->Phone << endl;
				j++;
			}
		}
	}
}

// ������������ ��������
void ShowList(list<Person*>& PL, string T) {
	int j = 1;
	int Count = 0;
	for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
		int T1 = atoi((*i)->Birth.c_str());
		int T2 = atoi(T.c_str());
		if (T1 >= T2) {
			Count++;
		}
	}
	if (Count == 0) {
		cout << "Not found" << endl;
	}
	else {
		cout << "N\tNAME\t\tYEAR\tPAY\tPHONE" << endl;
		for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
			int T1 = atoi((*i)->Birth.c_str());
			int T2 = atoi(T.c_str());
			if (T1 >= T2) {
				cout << j << "\t" << (*i)->Name << "\t" << (*i)->Birth << "\t" << (*i)->Pay << "\t" << (*i)->Phone << endl;
				j++;
			}
		}
		cout << "Count: " << --j << endl;
	}
}

// ����� ��� ������������ ��� ������������
void ShowUsers(list<User*>& UL) {
	int j = 1;
	cout << "N\tLOGIN\tPASS\tROLE" << endl;
	for (list<User*>::iterator i = UL.begin(); i != UL.end(); i++) {
		cout << j << "\t" << (*i)->Login << "\t" << (*i)->Password << "\t" << (*i)->Role << endl;
		j++;
	}
}

// ��������� ����������� ��� ������������
void AddUser(list<User*>& UL) {
	string Login;
	string Password;
	string Role;
	// ��������� ���������� ��� ��������� ������ �����������
	cout << "Enter login: ";
	getline(cin, Login);
	cout << "Enter password: ";
	getline(cin, Password);
	cout << "Enter role: ";
	getline(cin, Role);
	list<User*>::iterator t = UL.begin();
	for (list<User*>::iterator i = UL.begin(); i != UL.end(); i++) {
		if ((*i)->Login == Login) {
			t = i;
			break;
		}
	}
	if ((*t)->Login != Login) {
		// ����� ���������� � ����
		User* U = new User(Login, Password, Role);
		UL.push_back(U);
		fstream F("Users.txt", ios::app);
		F << Login;
		F << "\n";
		F << Password;
		F << "\n";
		F << Role;
		F << "\n";
		F.close();
	}
	else {
		cout << "This user already exists" << endl;
	}
}

// ��������� ����������� ��� ������������
void DeleteUser(list<User*>& UL) {
	string Login;
	cout << "Enter login: ";
	getline(cin, Login);
	list<User*>::iterator t = UL.begin();
	for (list<User*>::iterator i = UL.begin(); i != UL.end(); i++) {
		if ((*i)->Login == Login) {
			t = i;
			break;
		}
	}
	if ((*t)->Login == Login) {
		cout << "Are you sure you want to delete? Press Y or N" << endl;
		char Temp = _getch();
		if (Temp == 'y') {
			// ��������� �����������
			UL.erase(t);
			fstream F("Users.txt", ios::out | ios::trunc);
			for (list<User*>::iterator i = UL.begin(); i != UL.end(); i++) {
				// ����� ���������� � ����
				F << (*i)->Login;
				F << "\n";
				F << (*i)->Password;
				F << "\n";
				F << (*i)->Role;
				F << "\n";
			}
			F.close();
		}
	}
	else {
		cout << "Not found" << endl;
	}
}

// ����������� ����������� ��� ������������
void EditUser(list<User*>& UL) {
	string Login;
	cout << "Enter login in which you want do changes: ";
	getline(cin, Login);
	list<User*>::iterator t = UL.begin();
	for (list<User*>::iterator i = UL.begin(); i != UL.end(); i++) {
		if ((*i)->Login == Login) {
			t = i;
			break;
		}
	}
	if ((*t)->Login == Login) {
		string Password;
		string Role;
		cout << "Enter new password: ";
		getline(cin, Password);
		cout << "Enter new role: ";
		getline(cin, Role);
		// ���� ����������
		(*t)->Password = Password;
		(*t)->Role = Role;
		fstream F("Users.txt", ios::out | ios::trunc);
		for (list<User*>::iterator i = UL.begin(); i != UL.end(); i++) {
			// ����� ���������� � ����
			F << (*i)->Login;
			F << "\n";
			F << (*i)->Password;
			F << "\n";
			F << (*i)->Role;
			F << "\n";
		}
		F.close();
	}
	else {
		cout << "Not found" << endl;
	}
}


// ��������� ���������� ��� ������ ��� ������������
void AddInfo(list<Person*>& PL) {
	string Name;
	string Birth;
	string Pay;
	string Phone;
	// ����������� ������ ����� �������� ����� �������
	cout << "Enter name: ";
	getline(cin, Name);
	cout << "Enter year of connection: ";
	getline(cin, Birth);
	cout << "Enter pay: ";
	getline(cin, Pay);
	cout << "Enter phone: ";
	getline(cin, Phone);
	Person* P = new Person(Name, Birth, Pay, Phone);
	PL.push_back(P);
	// ����� ���������� � ����
	fstream F("Info.txt", ios::app);
	F << (*P).Name;
	F << "\n";
	F << (*P).Birth;
	F << "\n";
	F << (*P).Pay;
	F << "\n";
	F << (*P).Phone;
	F << "\n";
	F.close();
}

// ��������� ���������� ��� ������ ��� ������������
void DeleteInfo(list<Person*>& PL) {
	string Phone;
	// ����������� ����� ������� �� ����� ��� ���������
	cout << "Enter phone to delete info: ";
	getline(cin, Phone);
	list<Person*>::iterator t = PL.begin();
	for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
		if ((*i)->Phone == Phone) {
			t = i;
			break;
		}
	}
	if ((*t)->Phone == Phone) {
		cout << "Are you sure you want to delete? Press Y or N" << endl;
		char Temp = _getch();
		if (Temp == 'y') {
			PL.erase(t);
			fstream F("Info.txt", ios::out | ios::trunc);
			for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
				// ����� ���������� � ����
				F << (*i)->Name;
				F << "\n";
				F << (*i)->Birth;
				F << "\n";
				F << (*i)->Pay;
				F << "\n";
				F << (*i)->Phone;
				F << "\n";
			}
			F.close();
		}
	}
	else {
		cout << "Not found" << endl;
	}
}

// ����������� ���������� ��� ������������
void EditInfo(list<Person*>& PL) {
	string Phone;
	// ����������� ����� ������� �� ����� ��� ����
	cout << "Enter phone in which you want to do changes: ";
	getline(cin, Phone);
	list<Person*>::iterator t = PL.begin();
	for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
		if ((*i)->Phone == Phone) {
			t = i;
			break;
		}
	}
	if ((*t)->Phone == Phone) {
		string Name;
		string Birth;
		string Pay;
		cout << "Enter new name: ";
		getline(cin, Name);
		cout << "Enter new birth: ";
		getline(cin, Birth);
		cout << "Enter new pay: ";
		getline(cin, Pay);
		(*t)->Name = Name;
		(*t)->Birth = Birth;
		(*t)->Pay = Pay;
		fstream F("Info.txt", ios::out | ios::trunc);
		for (list<Person*>::iterator i = PL.begin(); i != PL.end(); i++) {
			// ����� ���������� � ����
			F << (*i)->Name;
			F << "\n";
			F << (*i)->Birth;
			F << "\n";
			F << (*i)->Pay;
			F << "\n";
			F << (*i)->Phone;
			F << "\n";
		}
		F.close();
	}
	else {
		cout << "Not found" << endl;
	}
}


// ������� �������
int main() {
	bool IsAdmin = false;
	// ��������� ���������� � �����
	list<User*> UL = GetUsers();
	list<Person*> PL = GetPeople();
	// �����������
	bool Authorized = false;
	while (true) {
		if (!Authorized) {
			cout << "Enter your login: ";
			string Login;
			getline(cin, Login);
			cout << "Enter your password: ";
			string Password;
			getline(cin, Password);
			for (list<User*>::iterator i = UL.begin(); i != UL.end(); i++) {
				if ((*i)->Login == Login && (*i)->Password == Password) {
					Authorized = true;
					if ((*i)->Role == "1") {
						IsAdmin = true;
					}
					break;
				}
			}
		}
		if (Authorized && !IsAdmin) {
			// ����
			system("cls");
			char Index;
			while (true) {
				cout << "(D)isplay" << endl;
				cout << "(E)nter data" << endl;
				cout << "(S)ort" << endl;
				cout << "Sea(R)ch" << endl;
				cout << "(Q)uit" << endl;
				Index = _getch();
				system("cls");
				if (Index == 'd') {
					Display(PL);
				}
				if (Index == 'e') {
					system("cls");
					cout << "Enter connection to search: ";
					string TBirth;
					getline(cin, TBirth);
					ShowList(PL, TBirth);
				}
				if (Index == 's') {
					system("cls");
					char SortIndex;
					while (true) {
						cout << "Sort by (N)ame" << endl;
						cout << "Sort by year of (C)onnection" << endl;
						cout << "Sort by (P)ay" << endl;
						cout << "(G)o back" << endl;
						SortIndex = _getch();
						system("cls");
						if (SortIndex == 'n') {
							SortByName(PL);
						}
						if (SortIndex == 'c') {
							SortByBirth(PL);
						}
						if (SortIndex == 'p') {
							SortByPay(PL);
						}
						if (SortIndex == 'g') {
							break;
						}
						cout << "Press any key to continue" << endl;
						_getch();
						system("cls");
					}
				}
				if (Index == 'r') {
					system("cls");
					char SearchIndex;
					while (true) {
						cout << "Search by (N)ame" << endl;
						cout << "Search by year of (C)onnection" << endl;
						cout << "Search by (P)ay" << endl;
						cout << "(G)o back" << endl;
						SearchIndex = _getch();
						system("cls");
						if (SearchIndex == 'n') {
							string T;
							cout << "Enter name to search: ";
							getline(cin, T);
							SearchByName(PL, T);
						}
						if (SearchIndex == 'c') {
							string T;
							cout << "Enter connection to search: ";
							getline(cin, T);
							SearchByBirth(PL, T);
						}
						if (SearchIndex == 'p') {
							string T;
							cout << "Enter pay to search: ";
							getline(cin, T);
							SearchByPay(PL, T);
						}
						if (SearchIndex == 'g') {
							break;
						}
						cout << "Press any key to continue" << endl;
						_getch();
						system("cls");
					}
				}
				if (Index == 'q') {
					system("cls");
					return 0;
				}
				cout << "Press any key to continue" << endl;
				_getch();
				system("cls");
			}
		}
		else if (Authorized && IsAdmin) {
			system("cls");
			char Index;
			while (true) {
				cout << "(D)isplay info" << endl;
				cout << "Display (U)sers" << endl;
				cout << "(A)dd user" << endl;
				cout << "(W)Edit user" << endl;
				cout << "De(L)ete user" << endl;
				cout << "Add (I)nfo" << endl;
				cout << "Edi(T) info" << endl;
				cout << "Delete in(F)o" << endl;
				cout << "(E)nter data" << endl;
				cout << "(S)ort" << endl;
				cout << "Sea(R)ch" << endl;
				cout << "(Q)uit" << endl;
				Index = _getch();
				system("cls");
				if (Index == 'u') {
					system("cls");
					ShowUsers(UL);
				}
				if (Index == 'a') {
					system("cls");
					AddUser(UL);
				}
				if (Index == 'l') {
					DeleteUser(UL);
				}
				if (Index == 'w') {
					EditUser(UL);
				}
				if (Index == 'i') {
					AddInfo(PL);
				}
				if (Index == 'f') {
					DeleteInfo(PL);
				}
				if (Index == 't') {
					EditInfo(PL);
				}
				if (Index == 'd') {
					Display(PL);
				}
				if (Index == 'e') {
					system("cls");
					cout << "Enter connection to search: ";
					string TBirth;
					getline(cin, TBirth);
					ShowList(PL, TBirth);
				}
				if (Index == 's') {
					system("cls");
					char SortIndex;
					while (true) {
						cout << "Sort by (N)ame" << endl;
						cout << "Sort by year of (C)onnection" << endl;
						cout << "Sort by (P)ay" << endl;
						cout << "(G)o back" << endl;
						SortIndex = _getch();
						system("cls");
						if (SortIndex == 'n') {
							SortByName(PL);
						}
						if (SortIndex == 'c') {
							SortByBirth(PL);
						}
						if (SortIndex == 'p') {
							SortByPay(PL);
						}
						if (SortIndex == 'g') {
							break;
						}
						cout << "Press any key to continue" << endl;
						_getch();
						system("cls");
					}
				}
				if (Index == 'r') {
					system("cls");
					char SearchIndex;
					while (true) {
						cout << "Search by (N)ame" << endl;
						cout << "Search by year of (C)onnection" << endl;
						cout << "Search by (P)ay" << endl;
						cout << "(G)o back" << endl;
						SearchIndex = _getch();
						system("cls");
						if (SearchIndex == 'n') {
							string T;
							cout << "Enter name to search: ";
							getline(cin, T);
							SearchByName(PL, T);
						}
						if (SearchIndex == 'c') {
							string T;
							cout << "Enter connection to search: ";
							getline(cin, T);
							SearchByBirth(PL, T);
						}
						if (SearchIndex == 'p') {
							string T;
							cout << "Enter pay to search: ";
							getline(cin, T);
							SearchByPay(PL, T);
						}
						if (SearchIndex == 'g') {
							break;
						}
						cout << "Press any key to continue" << endl;
						_getch();
						system("cls");
					}
				}
				if (Index == 'q') {
					system("cls");
					return 0;
				}
				cout << "Press any key to continue" << endl;
				_getch();
				system("cls");
			}
		}
		else {
			cout << "Wrong password or login. Try on again (Y or N)" << endl;
			char A = _getch();
			if (A == 'n') {
				break;
			}
			system("cls");
		}
	}
}
