#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int n, i = 0,ans=1,m;
	cin >> n;
	vector <int>a(n),k(1000000,0);
	rep(i, n) {
		cin >> a.at(i);
	}
	m = a.at(0);

	while (1) {
		if (ans>=n) {
			cout << -1 << endl;
			return 0;
		}
		if (m == 2) {
			cout << ans << endl;
			return 0;
		}
		m = a.at(m - 1);
		ans++;
	}	
	return 0;
}

