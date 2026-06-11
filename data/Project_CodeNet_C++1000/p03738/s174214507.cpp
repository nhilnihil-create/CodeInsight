#include<iostream>
#include<string>

using namespace std;


int main() {
	string a, b;
	cin >> a;
	cin >> b;
	if (a.size() > b.size()) {
		cout << "GREATER";
	}
	else if (a.size() < b.size()) {
		cout << "LESS";
	}
	else if (a.size() == b.size()) {
		if (a > b) {
			cout << "GREATER";
		}
		else if (a < b) {
			cout << "LESS";
		}
		else {
			cout << "EQUAL";
		}
	}
}