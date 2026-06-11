#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int t, n;
	cin >> t >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	int mx = 0;
	rep(i,n) mx = max(mx, v[i]);
	int k = t - mx;
	cout << max(0, mx - k - 1) << endl;
}