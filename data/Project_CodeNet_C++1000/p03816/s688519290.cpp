#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n;
	cin >> n;
	vector<int> a(n), b;
	rep(i, n)cin >> a[i];
	sort(all(a));
	rep(i, n-1)if(a[i] == a[i+1])b.push_back(a[i+1]);
	int ans = a.size()-b.size();
	int cnt = 0, s = b.size();
	while(s >= 3)s -= 2;
	if(s == 0)cnt = 0;
	if(s == 1)cnt = 1;
	if(s == 2)cnt = 0;
	cout << ans - cnt << endl;
}
