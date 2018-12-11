#pragma once
#include <string>
using namespace std;
class user {
	string username;
	string password;

public:
	user();
	user(string, string);
	string get_username();
	bool check_valid_password(string);

	bool operator == (string);
};

user::user() 
	:username(NULL), password(NULL)
{
	//Intentionally empty
}

user::user(string user, string pw)
	:username(user), password(pw)
{
	//Intentionally empty
}

string user::get_username() {
	return username;
}

bool user::check_valid_password(string input) {
	return input == password;
}

bool user::operator == (string input) {
	return input == username;
}

