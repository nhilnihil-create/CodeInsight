#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> vec(3);
	for (int i=0; i<3; i++)
		cin >> vec[i];

	int c5 = 0;
	int c7 = 0;
	for (int i=0; i<3; i++) {
		if (vec[i] == 5)
			c5++;
		if (vec[i] == 7)
			c7++;
	}

	if (c5 == 2 && c7 == 1)
		cout << "YES";
	else
		cout << "NO";

	
}