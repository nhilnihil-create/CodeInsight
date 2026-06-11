#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-6
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int high, low, ori;
string pre, sys, big;

int main() {
	ios::sync_with_stdio(false);
	big = "999999999";
	string notsobig = "999999";
	while (1) {
		high = 10;
		if (pre.size()) low = 0;
		else low = 1;
		ori = low;
		while (low < high) {
			int mid = (low + high) / 2;
			if (pre.size() > 7) cout << "? " << pre << mid << notsobig << endl;
			else cout << "? " << pre << mid << big << endl;
			cout.flush();
			cin >> sys;
			if (sys == "N") low = mid + 1;
			else high = mid;
		}
		int cur = high;
		bool term = false;
		if (cur != ori) {
			cout << "? " << pre << ori << 0 << endl;
			cout.flush();
			cin >> sys;
			if (sys == "N") term = true;
		} else {
			cout << "? " << pre << 9 << endl;
			cout.flush();
			cin >> sys;
			if (sys == "Y") term = true;
		}
		pre += (char)('0' + cur);
		if (term) {
			cout << "! " << pre << endl;
			return 0;
		}
	}
}