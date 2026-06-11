#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<climits>
 
using namespace std;
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long n, m, x;
	cin >> n >> m;
	long long xx = 0;
	long long yy = 0;
	long long mod = 1000 * 1000 * 1000 + 7;
	for (long long i = 0; i < n; i++) {
		cin >> x;
		xx += (2 * i + 1 - n)*x;
		xx %= mod;
	}
	for (long long i = 0; i < m; i++) {
		cin >> x;
		yy += (2 * i + 1 - m)*x;
		yy %= mod;
	}

	cout << (xx*yy)%mod << endl;
	return 0;
}