#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int k, t;
	cin >> k >> t;
	int m = 0;
	rep(i, t) {
		int ki;
		cin >> ki;
		m = max(m, ki);
	}
	int n = k - m;
	if (n >= m - 1) {
		cout << 0 << endl;
	}
	else {
		cout << m - n - 1 << endl;
	}
}