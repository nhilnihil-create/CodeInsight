#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL<<60;
const ll mod = 1000000007;		




int main() {
	
	int n, k;
	cin >> n >> k;
	VLL a(n);
	REP(i, n)cin >> a[i];

	sort(ALL(a));

	int ok = n;
	int ng = -1;

	while (ok - ng > 1) {
		int mid = (ok + ng) / 2;

		

		if (a[mid] >= k) {
			ok = mid;
			continue;
		}

		vector<bool> b(k, false);
		b[0] = true;
		REP(i, mid) {
			for (int j = k - 1; j >= a[i]; j--) {
				if (b[j - a[i]])b[j] = true;
			}
		}
		FOR(i, mid+1, n) {
			for (int j = k - 1; j >= a[i]; j--) {
				if (b[j - a[i]])b[j] = true;
			}
		}
		bool bb = false;
		for (int i = k - 1; i >= max(0LL, k - a[mid]); i--) {
			if (b[i])bb = true;
		}
		if (bb)ok = mid;
		else ng = mid;
	}
	cout << ok << endl;

}