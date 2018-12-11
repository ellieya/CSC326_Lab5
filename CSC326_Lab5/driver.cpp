#include <iostream>
#include <fstream>
#include <cassert>
#include "user.h"
#include "BST.h"

using namespace std;

int main() {

	BST<user> main_BST;

	input_file(main_BST);
	ask_credentials();


	return 0;
}

void ask_credentials(BST<user> main_BST) {

	string un, pw;
	user holder;

	//Ideal to use getline instead
	cout << "Username: ";
	cin >> un;
	cout << "Password: ";
	cin >> pw;

	holder = user(un, pw);

	search_credentials(main_BST, holder);
}

void search_credentials(BST<user> main_BST, user target) {
	if (main_BST.search(target)) {

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