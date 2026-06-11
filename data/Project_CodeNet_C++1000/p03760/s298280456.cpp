// ABC058B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	string O, E;
	cin >> O >> E;

	for (int i = 0; i < O.size(); i++) {
		cout << O[i];
		if (i >= E.size()) {
			break;
		}
		cout << E[i];
	}
	cout << endl;

	return 0;
}
