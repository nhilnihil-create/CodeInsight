#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	s.insert(s.begin()+4, ' ');
	cout << s << endl;
}
