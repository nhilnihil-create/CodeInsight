#include<iostream>
#include<vector>
using namespace std;
int main() {
	string S;
	cin >> S;
	vector<int> a(1000);
	for (int i = 0; i < S.length(); i++) {
		a[S[i] - 'a']++;
	}
	bool check = true;
	for (int i = 0; i < 1000; i++) {
		if (a[i] > 1) {
			check = false;
		}
	}
	if (check) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}