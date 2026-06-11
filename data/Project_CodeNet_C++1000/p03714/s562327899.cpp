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
#define ld long double
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
const int N = 3e5 + 5, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
ll a[N] = { };
vl v;
priority_queue<ll, vl, greater<ll>> pq;
unordered_map<ll, set<int>> pos;
set<int> st;
int main() {
#ifdef ONLINE_JUDGE
	   FAST;
#endif
	int n, R;
	ll sum = 0, sum2 = 0, ans = -1e15;
	cin >> n;
	R = n - 1;
	lp(i,0,n*3-1)
	{
		cin >> a[i];
		if (i >= n)
			v.pb(a[i]);
		else {
			pq.push(a[i]);
			sum += a[i];
		}
	}
	sort(all(v));
	lp(i,0,v.size()-1)
	{
		pos[v[i]].insert(i);
		if (i < n)
			sum2 += v[i];
		st.insert(i);
	}
	ans = max(ans, sum - sum2);
	lp(i,n,2*n-1)
	{
		ll x;
		if (a[i] > pq.top()) {
			x = pq.top();
			sum -= x;
			sum += a[i];
			pq.pop();
			pq.push(a[i]);
		}
		x = *pos[a[i]].rbegin();
		pos[a[i]].erase(x);
		st.erase(x);
		if (x <= R) {
			R++;
			sum2 -= a[i];
			x = *st.lower_bound(R);
			sum2 += v[x];
			R = x;
		}
		ans = max(ans, sum - sum2);
	}
	f(ans);
	return 0;
}