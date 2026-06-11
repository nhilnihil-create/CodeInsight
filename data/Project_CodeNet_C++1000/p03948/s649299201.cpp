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
	int n, t, a; int i,j;
	cin >> n >> t;
	int x[100000]; int mi[100000]; int ma[100000] = {}; vector<int> s;
	for (i = 0; i < n; i++) {
		cin >> a; x[i] = a;
	}
	mi[0] = x[0]; ma[n - 1] = x[n - 1];
	for (i = 1; i < n; i++) {
		mi[i] = min(mi[i - 1], x[i]);
		ma[n - 1 - i] = max(ma[n - i], x[n - 1 - i]);
	}
	int cma = -1; int memo;
	for (i = 0; i < n; i++) {
		if (cma < ma[i] - mi[i]) {
			cma = ma[i] - mi[i];
			s.clear();
			s.push_back(mi[i]); s.push_back(ma[i]); memo = mi[i];
		}
		else if (cma == ma[i] - mi[i]) {
			if (mi[i] < memo) {
				s.push_back(mi[i]), s.push_back(ma[i]); memo = mi[i];
			}
		}
	}
	int len = s.size();
	int out = 0; int check = 0;
	for (i = 0; i < len/2; i++) {
		int count=0; bool f=true;
		for (j = check; j < n; j++) {
			if (i < len / 2 - 1 && s[2 * (i + 1)] == x[j])break;
			if (f&&s[2 * i + 1] == x[j]) {
				f = false; count++;
			}
			if (s[2 * i] == x[j])f = true;
		}
		check = j;
		out += count;
	}
	cout << out << endl;
	return 0;
}