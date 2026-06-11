//============================================================================
// Name        : hoba.cpp :)
// Author      : (O_O Diab) (Why_not) (el 3AQ)
// Version     :
// Copyright   : please, Don't touch me :(
// Description : problem in C++
// MAIN IDEA   :
//============================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define rw freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define pb push_back
#define F first
#define S second
#define pf push_front
#define lp(i,a,b) for (int i=a;i<=(int)b;++i)
#define lp2(i,a,b) for (int i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cerr<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define EPS 1e-6
// to convert string to number use int a = stoi(string);
// to convert number to string use string s = to_string(int);
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define clr(c,x) memset(c,x,sizeof(c));
using namespace __gnu_pbds;
using namespace std;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int N = 5e3 + 1, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
vi v;
int n, k, x, ig, dp1[N][N] = { }, dp2[N][N] = { };
int rig(int idx, int rem) {
	if (rem <= 0)
		return 0;
	if (idx >= (int) v.size())
		return 1e9;
	int &ret = dp1[idx][rem];
	if (ret != -1)
		return ret;
	ret = 1e9;
	ret = min(ret, rig(idx + 1, rem - v[idx]) + v[idx]);
	ret = min(ret, rig(idx + 1, rem));
	return ret;
}
int lef(int idx, int rem) {
	if (rem <= 0)
		return 0;
	if (idx < 0)
		return 1e9;
	int &ret = dp2[idx][rem];
	if (ret != -1)
		return ret;
	ret = 1e9;
	ret = min(ret, lef(idx - 1, rem - v[idx]) + v[idx]);
	ret = min(ret, lef(idx - 1, rem));
	return ret;
}
int main() {
#ifdef ONLINE_JUDGE
	FAST
#endif
	clr(dp1, -1);
	clr(dp2, -1);
	cin >> n >> k;
	lp(i,1,n)
	{
		cin >> x;
		if (x >= k) {
			ig++;
			continue;
		}
		v.pb(x);
	}
	sort(all(v));
	lp(i,0,v.size()-1)
	{
		x = k - v[i];
		lp(j,0,x)
		{
			ll l = lef(i - 1, j);
			ll r = rig(i + 1, x - j);
			if (i - 1 < 0)
				l = 0;
			if (i + 1 >= (int) v.size())
				r = 0;
//			if (i == 1) {
//				p(l);
//				p(r);
//			}
			if ((l + r < (ll) k) && (l + r + (ll) v[i] >= (ll) k)) {
				ig++;
				//			p(i);
				break;
			}
		}
	}
	cout << n - ig << "\n";
	return 0;
}