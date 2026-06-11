#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	cout << setprecision(20) << pow(k-1,n-1)*k << endl;

	return 0;
}