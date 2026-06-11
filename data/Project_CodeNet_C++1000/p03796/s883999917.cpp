#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
const int mod = 1e9 + 7; 
int main() {
	int n;
	cin >> n;
	ll fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
		fact %= mod;
	}
	cout << fact << endl;
	
	return 0;
}