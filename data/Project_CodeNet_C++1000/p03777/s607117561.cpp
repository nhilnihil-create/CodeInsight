#include <iostream>
using namespace std;

int main() {
	string a , b;
	cin >> a >> b;
	if ( a == "H" && b == "H") cout << "H";
	if ( a == "H" && b == "D") cout << "D";
	if ( a == "D" && b == "H") cout << "D";
	if ( a == "D" && b == "D") cout << "H";
}
