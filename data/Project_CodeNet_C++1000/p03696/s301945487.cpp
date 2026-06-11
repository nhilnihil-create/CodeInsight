#include <bits/stdc++.h>

using namespace std;

int main() {

	long n;
	cin >> n;

	deque<char> s;
	char ss;
	for (long i = 0; i < n; i++) {
		cin >> ss;
		s.push_back(ss);
	}

	deque<char>::iterator itr=s.begin();
	long counter = 0;
	while (1) {
		if (*itr == ')') {
			counter--;
		}
		if (*itr == '(') {
			counter++;
		}
		if (counter < 0) {
			s.push_front('(');
			itr = s.begin();
			counter = 0;
			continue;
		}
		itr++;
		if (itr >= s.end()) { break; }
	}
	itr = s.end()-1;
	counter = 0;
	while (1) {
		if (*itr == ')') {
			counter--;
		}
		if (*itr == '(') {
			counter++;
		}
		if (counter > 0) {
			s.push_back(')');
			itr = s.end()-1;
			counter = 0;
			continue;
		}
		if (itr <= s.begin()) { break; }
		itr--;
	}

	for (long i = 0; i < s.size(); i++) {
		cout << s[i] ;
	}
}