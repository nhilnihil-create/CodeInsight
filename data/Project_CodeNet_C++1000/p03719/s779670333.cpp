// ABC061A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if ((A <= C)&&(C <= B)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
