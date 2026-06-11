#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string w;
	cin >> w;
	int A[100] = {0};
	for (int i = 0; i < w.length(); i++) {
		A[w[i]-'a']++;
	}
	int rec = 0;
	for (int i = 0; i < w.length(); i++) {
		if (A[w[i]-'a'] % 2 != 0) {
			rec++;
		}
	}
	if (rec == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}