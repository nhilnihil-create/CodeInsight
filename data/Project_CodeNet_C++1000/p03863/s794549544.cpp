#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	cin >> s;
	if ((s.front() == s.back()) ^ (s.size() % 2 == 0)) {
		cout << "Second" << endl;
	}
	else cout << "First" << endl;
	return 0;
}