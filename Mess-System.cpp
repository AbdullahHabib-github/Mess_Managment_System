#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include<vector>
using namespace std;


vector< vector<string> > record;
vector <string> student;

string filename = "data.csv", regno;



void intro();
void mainmenu();
void display();
bool check(string regno);
void sort();
void Regnew();
void search();
void status();
int check_index(string regno);
void delstudent();
void IOCounter();
void totalbill();
void dayincrement();
void read_file();
void filesaving();
void exit();



int main() {

	read_file();

	char c;
	intro();

	do {
		system("cls");
		cout << "\n\n";
		cout << "\t====================STUDENT MESS RECORD MANEGEMENT SYSTEM====================" << endl;
		cout << endl;
		cout << "\t\t\t\t1. MAIN MENU\n\n";
		cout << "\t\t\t\t2. EXIT\n\n";
		cout << "ENTER YOUR CHOICE :";
		cin >> c;
		system("cls");

		switch (c)
		{
		case '1':
		{
			mainmenu();
			break;
		}
		case '2':
		{

			filesaving();
			exit();
			break;
		}
		}


	} while (c != '2');


}

void intro()

{

	cout << "\n\n\n";

	cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;

	cout << "\t\t\t\t * * * *     *     *     *   * * * * *        " << endl;

	cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;

	cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;

	cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;

	cout << endl;
	cout << "\t\t\t\t=============================================" << endl;

	cout << "\t\t\t\t   THIS IS STUDENT MESS MANEGEMENT SYSTEM" << endl;

	cout << "\t\t\t\t=============================================" << endl;


	cout << endl << endl;

	system("pause");
}

void mainmenu()

{

	char cc;
	cout << "\t\t\t\t=================MAIN MENU================\n\n" << endl;

	cout << "\t\t\t\t1. REGISTER A NEW STUDENT\n\n" << endl;

	cout << "\t\t\t\t2. VIEW A SINGLE STUDENT'S RECORD\n\n" << endl;

	cout << "\t\t\t\t3. CHANGE A STUDENT'S STATUS\n\n" << endl;

	cout << "\t\t\t\t4. DELETE  A STUDENT'S RECORD\n\n\n\n" << endl;

	cout << "\t\t\t\t5. SHOW A TOTAL NUMBER OF IN/OUT STUDENTS\n\n" << endl;

	cout << "\t\t\t\t6. CALCULATE TOTAL BILL\n\n" << endl;

	cout << "\t\t\t\t7. 1+, TO INCREASE THE NUMBER OF DAYS (TO BE DONE EVERYDAY)\n\n" << endl;

	cout << "\t\t\t\t==============================" << endl;

	cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-7> :";

	cin >> cc;
	cout << endl;
	switch (cc)
	{
	case '1':
	{
		Regnew();
		break;
	}

	case '2':
	{
		search();
		break;
	}

	case '3': {
		status();
		break;
	}

	case '4': {
		delstudent();
		break;
	}

	case '5': {

		IOCounter();
		break;
	}

	case '6':
	{
		totalbill();
		break;
	}

	case '7':
	{
		dayincrement();
		break;
	}
	}
}

bool check(string regno) {

	int rows = record.size();

	for (int i = 0; i < rows; i++) {
		if (record[i][0] == regno) {
			return true;
		}
	}
	return false;
}

void sort() {

	string temp;

	int rows = record.size();
	int cols = 5;

	for (int i = 1; i < rows - 1; i++) {
		for (int k = 1; k < rows - 1; k++) {
			stringstream int_stud(record[k][0]);
			stringstream int_studnext(record[k + 1][0]);
			int currentstudent;
			int nextstudent;
			int_stud >> currentstudent;
			int_studnext >> nextstudent;

			if (currentstudent > nextstudent) {
				for (int m = 0; m < 5; m++) {

					temp = record[k][m];
					record[k][m] = record[k + 1][m];
					record[k + 1][m] = temp;
				}
			}
		}
	}
}

void Regnew() {

	system("cls");

	string name;

	cout << "\n\n";
	cout << "\t\t\t\t=======REGISTER A NEW STUDENT========\n\n";

	cout << "ENTER YOUR REGISTRATION NUMBER :";
	cin >> regno;

	cout << "ENTER YOUR FULL NAME :";
	cin.ignore();
	getline(cin, name);

	if (check(regno) == false) {
		student = { regno,name,"Out","0","0" };



		record.push_back(student);

		sort();

		cout << "==============================================================================================================" << endl;
		cout << "==============================================================================================================" << endl;
		cout << "||||||||||                         THE STUDENT IS SUCCESSFULLY REGISTERED                        |||||||||||||" << endl;
		cout << "==============================================================================================================" << endl;
		cout << "==============================================================================================================" << endl;

	}

	else {
		cout << "\t\t\t\tTHE STUDENT IS ALREADY REGISTERED" << endl;
	}

	cout << "\n" << endl;
	system("pause");



}

void search() {

	system("cls");


	cout << "\n\n";
	cout << "\t\t\t\t=======SEARCH A STUDENT RECORD========\n\n";

	cout << "ENTER YOUR REGISTRATION NUMBER :";
	cin >> regno;

	cout << "\n\n" << endl;

	int rows = record.size();

	if (check(regno) == true) {

		for (int i = 0; i < rows; i++) {

			if (regno == record[i][0]) {

				cout << "\t\tNAME :" << record[i][1] << "\n\n" << endl;

				cout << "\t\tREGISTRATION NUMBER :" << record[i][0] << "\n\n" << endl;

				cout << "\t\tIN/OUT STATUS :" << record[i][2] << "\n\n" << endl;

				cout << "\t\tTOTAL NUMBER OF DAYS :" << record[i][3] << "\n\n" << endl;

				cout << "\t\tTOTAL BILL :" << record[i][4] << "\n\n" << endl;

			}
		}
	}
	else {
		cout << "\t\t\t\tTHE STUDENT IS NOT REGISTERED" << endl;
	}


	cout << "\n" << endl;
	system("pause");

}

void status() {

	system("cls");


	cout << "\n\n";
	cout << "\t\t\t\t=======CHANGING A STUDENT'S STATUS========\n\n";

	cout << "ENTER YOUR REGISTRATION NUMBER :";
	cin >> regno;

	int rows = record.size();

	if (check(regno) == true) {


		for (int i = 0; i < rows; i++) {

			if (regno == record[i][0]) {

				char p;

				cout << "\t\tNAME :" << record[i][1] << "\n\n" << endl;

				cout << "\t\tREGISTRATION NUMBER :" << record[i][0] << "\n\n" << endl;

				cout << "\t\tIN/OUT STATUS :" << record[i][2] << "\n\n" << endl;

				cout << "\t\tDO YOU WANT TO CHANGE THE STATUS? (Y/N)" << endl;

				cin >> p;

				if (p == 'y' || p == 'Y') {

					if (record[i][2] == "Out") {
						record[i][2] = "In";
					}
					else if (record[i][2] == "In") {
						record[i][2] = "Out";
					}
				}
			}
		}

		cout << "==============================================================================================================" << endl;
		cout << "==============================================================================================================" << endl;
		cout << "||||||||||                               Task Completed Successfully!                            |||||||||||||" << endl;
		cout << "==============================================================================================================" << endl;
		cout << "==============================================================================================================" << endl;
	}
	else {
		cout << "\t\t\t\tTHE STUDENT IS NOT REGISTERED" << endl;
	}

	cout << "\n" << endl;
	system("pause");


}

int check_index(string regno) {

	int rows = record.size();

	for (int i = 0; i < rows; i++) {
		if (record[i][0] == regno) {
			return i;
		}
	}

}

void delstudent() {

	system("cls");


	cout << "\n\n";
	cout << "\t\t\t\t=======DELETING A STUDENT'S RECORD========\n\n";

	cout << "ENTER YOUR REGISTRATION NUMBER :";
	cin >> regno;

	if (check(regno) == true) {

		int index = check_index(regno);

		record.erase(record.begin() + index);

		sort();

		cout << "==============================================================================================================" << endl;
		cout << "==============================================================================================================" << endl;
		cout << "||||||||||                               Record Deleted Successfully!                            |||||||||||||" << endl;
		cout << "==============================================================================================================" << endl;
		cout << "==============================================================================================================" << endl;
	}

	else {
		cout << "\t\t\t\tTHE STUDENT IS NOT REGISTERED" << endl;
	}

	cout << "\n" << endl;
	system("pause");
}

void IOCounter() {

	int rows = record.size();
	int in = 0;
	int out = 0;

	for (int i = 0; i < rows; i++) {

		if (record[i][2] == "Out") {
			out = out + 1;
		}
		else {
			in = in + 1;
		}

	}

	cout << "\t\tTHE NUMBER OF STUDENTS WITH IN IS : " << in << "\n\n" << endl;
	cout << "\t\tTHE NUMBER OF STUDENTS WITH OUT IS : " << out << endl;

}

void totalbill() {

	system("cls");


	cout << "\n\n";
	cout << "\t\t\t\t=======SEARCH A STUDENT'S TOTAL BILL========\n\n";

	cout << "\t\tENTER YOUR REGISTRATION NUMBER :";
	cin >> regno;

	cout << endl;

	int rows = record.size();

	if (check(regno) == true) {


		for (int i = 0; i < rows; i++) {

			if (regno == record[i][0]) {

				cout << "\t\tYOUR TOTAL IS BILL : Rs." << record[i][4] << "\n\n" << endl;
			}
		}

	}

	else {
		cout << "\t\t\t\tTHE STUDENT IS NOT REGISTERED" << endl;
	}


	cout << "\n" << endl;
	system("pause");

}

void dayincrement() {

	system("cls");


	cout << "\n\n";
	cout << "\t\t\t\t=======INCREASING NUMBER OF DAYS========\n\n";

	cout << "\t\tENTER YOUR REGISTRATION NUMBER :";
	cin >> regno;

	cout << endl;

	int rows = record.size();

	if (check(regno) == true) {


		for (int i = 0; i < rows; i++) {

			if (regno == record[i][0]) {

				if (record[i][2] == "In") {

					stringstream int_day(record[i][3]);
					stringstream int_bill(record[i][4]);

					int total_days;
					int total_bill;

					int_day >> total_days;
					int_bill >> total_bill;

					total_days = total_days + 1;
					total_bill = total_bill + 300;

					record[i][3] = to_string(total_days);
					record[i][4] = to_string(total_bill);


					cout << "==============================================================================================================" << endl;
					cout << "==============================================================================================================" << endl;
					cout << "||||||||||                               Task Completed Successfully!                            |||||||||||||" << endl;
					cout << "==============================================================================================================" << endl;
					cout << "==============================================================================================================" << endl;
				}
				else {
					cout << "\t\t\t\tTHE STUDENT STATUS IS NOT IN, CHANGE THE STATUS TO IN TO +1\n\n" << endl;
				}

			}
		}
	}

	else {
		cout << "\t\t\t\tTHE STUDENT IS NOT REGISTERED" << endl;
	}


	cout << "\n" << endl;
	system("pause");

}

void read_file()
{
	string word, line;
	fstream myfile(filename, ios::in);

	vector <string> student2;
	while (getline(myfile, line))
	{
		student2.clear();
		stringstream row(line);
		while (getline(row, word, ','))
		{
			student2.push_back(word);
		}

		record.push_back(student2);
	}

	//display();
}

void display()
{
	for (int r = 0; r < record.size(); r++)
	{
		for (int c = 0; c < record[1].size(); c++)
		{
			cout << record[r][c] << "\t";
		}
		cout << endl;
	}
}

void filesaving() {

	sort();

	int rows = record.size();

	fstream myfile;
	myfile.open(filename, ios::out);

	if (myfile.is_open()) {

		for (int i = 0; i < rows; i++) {
			for (int k = 0; k < 5; k++) {

				myfile << record[i][k];

				if (k < 4) {
					myfile << ",";
				}

			}
			myfile << endl;

		}
		myfile.close();
	}

	else {
		cout << "file can not be saved" << endl;

	}
}

void exit() {

	cout << "\t\t                            FILE SAVED SUCCESSFULLY\n\n" << endl;

	cout << "\t\t                            SEMESTER PROJECT FOR LAB\n\n" << endl;

	cout << "\t\t                        THANK YOU FOR USING THIS SOFTWARE" << endl;

	cout << "\n\n";
	cout << " DEVELOPER:";
	cout << "\n\n";
	cout << "\t                    NAME:                 REG#:          FACULTY:        COURSE: \n\n";
	cout << "\t               ABDULLAH HABIB            2021033          BSAI          CS-103(l)   \n\n";
	cout << "\n\n";
	cout << "\t\t\t\t\t\t\t\t\t   SUBMITED TO:   SIR JALEES UR RAHMAN\n";


	cout << "\n\n";
}

