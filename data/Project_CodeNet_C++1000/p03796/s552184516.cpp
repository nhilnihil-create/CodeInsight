#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
	long n; cin >> n;
	long res = 1;
	for (int i = 2; i <= n; i++)
	{
		res = res * i % mod;
	}
	cout << res << endl;
	return 0;
}
