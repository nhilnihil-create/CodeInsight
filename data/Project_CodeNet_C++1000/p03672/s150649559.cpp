#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	while(1) {
		s.pop_back();
		string x = s.substr(0, s.size() / 2);
		string y = s.substr(s.size() / 2, s.size() / 2);
		if (x == y) {
			cout << x.size()+y.size() << endl;
			return 0;
		}
	}
}
