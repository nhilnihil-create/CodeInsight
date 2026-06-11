#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main(){
	int n, t, a; int i;
	cin >> n >> t;
	int x[100000]; int mi[100000]; int ma[100000] = {};
	for (i = 0; i < n; i++) {
		cin >> a; x[i] = a;
	}
	mi[0] = x[0]; ma[n - 1] = x[n - 1];
	for (i = 1; i < n; i++) {
		mi[i] = min(mi[i - 1], x[i]);
		ma[n - 1 - i] = max(ma[n - i], x[n - 1 - i]);
	}
	int cma = 0; int memo; int count;
	for (i = 0; i < n; i++) {
		if (cma < ma[i] - mi[i]) {
			cma = ma[i] - mi[i];
			memo = mi[i];
			count = 1;
		}
		else if (cma == ma[i] - mi[i] && mi[i] < memo) {
			memo = mi[i]; count++;
		}
	}
	cout << count << endl;
	return 0;
}