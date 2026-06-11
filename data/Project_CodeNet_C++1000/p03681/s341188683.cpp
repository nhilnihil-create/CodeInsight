#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;
const ll mod = 1000000007ll;


int main() {
	int n, m;
	cin >> n >> m;
	if (abs(n-m)>1) {
		cout << 0 << endl;
		return 0;
	}
	else {
		ll nn = 1;
		int nc = n;
		int mc = m;
		while(n>0) {
			nn *= n;
			nn %= mod;
			n--;
		}
		ll mm = 1;
		while(m>0) {
			mm *= m;
			mm %= mod;
			m--;
		}
		if (nc==mc) cout << (2*mm*nn)%mod << endl;
		else cout << (mm*nn)%mod << endl;
	}
}