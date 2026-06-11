#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	vector<string> a;
	int N, L;
	string s;
	cin >> N >> L;

	while (N != 0) {
		cin >> s;
		a.push_back(s);
		N -= 1;
	}

	sort(a.begin(), a.end());

	vector<string>::iterator i;

	for (i = a.begin(); i != a.end(); i++) {
		cout << *i;
	}

	cout << endl;

	return 0;
}