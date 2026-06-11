#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
    cin >> N;
	string s;
	cin >> s;
    list<char> S;
    for (int i = 0; i < N; i++) {
        S.push_back(s[i]);
    }
	list<char> A;
	for (int i = 0; i < N; i++) {
		if (A.back() == '(' && s[i] == ')') {
			A.pop_back();
		} else {
			A.push_back(s[i]);
		}
	}
    while (A.back() == '(') {
        A.pop_back();
        S.push_back(')');
    }
    while (A.front() == ')') {
        A.pop_front();
        S.push_front('(');
    }
    for (auto it = S.begin(); it != S.end(); it ++) {
        cout << *it;
    }
    cout << endl;
	return 0;
}