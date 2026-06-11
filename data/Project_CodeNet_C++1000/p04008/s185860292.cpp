
#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

#define N 100010
int ans = 0;
int n, k;
vi a(N);
vii G(N, vi());

int dfs(int now) {
	int i;
	int height = 0;
	for (i = 0; i < G[now].size(); i++) {
		height = max(height, dfs(G[now][i]) + 1);
	}
	if (height == k - 1 && a[now] != 0) {
		ans++;
		return -1;
	}
	else {
		return height;
	}
}

int main() {
	int i, j;
	cin >> n >> k;
	cin >> a[0];
	a[0]--;
	if (a[0] != 0) {
		a[0] = 0;
		ans++;
	}
	for (i = 1; i < n; i++) {
		cin >> a[i];
		a[i]--;
		G[a[i]].push_back(i);
	}
	dfs(0);
	cout << ans << endl;
}