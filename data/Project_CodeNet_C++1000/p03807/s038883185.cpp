#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int a; cin >> a; cnt += (a % 2);
	}
	cout << (cnt & 1 ? "NO" : "YES") << endl;
}	