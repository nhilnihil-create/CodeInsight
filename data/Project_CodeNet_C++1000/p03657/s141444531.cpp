// ABC067A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int A, B;
	cin >> A >> B;

	if ((A % 3 == 0)||(B % 3 == 0)||((A + B)% 3 == 0)) {
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}

	return 0;
}
