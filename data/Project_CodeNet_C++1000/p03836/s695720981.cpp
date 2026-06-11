#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;
	rep(i, tx - sx) cout << "R";
	rep(i, ty - sy) cout << "U";
	rep(i, tx - sx) cout << "L";
	rep(i, ty - sy) cout << "D";
	cout << "D";
	rep(i, tx - sx + 1) cout << "R";
	rep(i, ty - sy + 1) cout << "U";
	cout << "L";
	cout << "U";
	rep(i, tx - sx + 1) cout << "L";
	rep(i, ty - sy + 1) cout << "D";
	cout << "R";
	cout << endl;


  return 0;
}
