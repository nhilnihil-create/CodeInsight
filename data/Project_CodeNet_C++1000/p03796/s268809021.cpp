#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	unsigned long long power = 1;

	for (int loop = 1; loop <= n; ++loop) {
		power *= loop;
		power %= 1000000000 + 7;
	}

	cout << power << endl;

	return 0;
}
