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

	friend ostream& operator <<(ostream&, user);
	friend bool operator == (user, user);
	friend bool operator > (user, user);
	friend bool operator < (user, user);
};


user::user() 
	:username("DUMMY"), password("DUMMY")
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

bool operator == (user left, user right) {
	return left.password == right.password;
}

bool operator <(user left, user right) {
	return left.username < right.username;
}

bool operator >(user left, user right) {
	return left.username > right.username;
}

ostream& operator <<(ostream& out, user input) {
	out << "U: " << input.username << " P: " << input.username << endl;
	return out;
}