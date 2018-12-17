#include <iostream>
#include <fstream>
#include <cassert>
#include "user.h"
#include "BST.h"

using namespace std;

void input_file(BST<user>&);
user ask_credentials(BST<user>);
void search_credentials(BST<user>, user);
void print_all(BST<user>);


int main() {

	BST<user> main_BST;
	user holder;
	char user_input;
	bool try_again = true;

	input_file(main_BST);

	while (try_again) {
		holder = ask_credentials(main_BST);
		search_credentials(main_BST, holder);
		cout << "\nTry again? (Y): ";
		cin >> user_input;
		cin.ignore();
		cout << '\n';

		if (user_input == 'Y' || user_input == 'y')
			try_again = true;
		else
			try_again = false;
	}

	cout << "Printing all of BST.." << endl;
	print_all(main_BST);

	system("pause");
	return 0;
}

user ask_credentials(BST<user> main_BST) {

	string un, pw;
	user holder;

	//Ideal to use getline instead
	cout << "Username: ";
	getline(cin, un);
	cout << "Password: ";
	getline(cin, pw);

	return user(un, pw);
}

void search_credentials(BST<user> main_BST, user input) {

	user holder;
	

	try {
		holder = main_BST.search(input);
		//At this point, input has been updated to contain data retrieved from search.
		//Check password match
		if (input == holder)
			cout << "Login successful!" << endl;
		else
			cout << "Invalid password!" << endl;
	}
	catch (int error) {
		cout << "User not found!" << endl;
	}
}

void input_file(BST<user>& main_BST) {
	ifstream ifile;
	ifile.open("log.txt");

	assert(!ifile.fail());

	user holder;
	string holder_un, holder_pw;
	while (!ifile.eof()) {
		ifile >> holder_un >> holder_pw;
		holder = user(holder_un, holder_pw);		
		main_BST.insert(holder);
	}
}

void print_all(BST<user> main_BST) {
	main_BST.inorder(cout);
}

/*

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
OUTPUT
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Username: test
Password: test1
User not found!

Try again? (Y): Y

Username: username
Password: wrong pw
Invalid password!

Try again? (Y): Y

Username: username
Password: password
Login successful!

Try again? (Y): N

Printing all of BST..
U: ai_should_be_first P: ai_should_be_first
U: b_should_be_second P: b_should_be_second
U: c_should_be_third P: c_should_be_third
U: d_deliciously_4th P: d_deliciously_4th
U: ultraun P: ultraun
U: username P: username
U: weakusername P: weakusername
Press any key to continue . . .

*/