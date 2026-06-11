#include<iostream>
#include<string>
using namespace std;
int main() {
	string s,ss;
	cin >> s;
	int j = 0;
	for (int i = 0; i < s.size();i++) {
		if (i % 2 == 0) {
			ss.push_back(j);
			ss.at(j++) = s.at(i);
		}
	}
	cout << ss << endl;


}