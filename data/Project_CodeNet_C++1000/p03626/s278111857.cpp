//============================================================================
// Name        : hoba.cpp :)
// Author      : (O_O Diab) (Why_not) (el 3AQ)
// Version     :
// Copyright   : please, Don't touch me :(
// Description : problem in C++
// MAIN IDEA   : combinatorics NCR
//============================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define rw freopen("graphs_as_a_service.txt","r",stdin),freopen("output.txt","w",stdout);
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
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
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
const int N = 1e5 + 10, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
int dp[55][4][4] = { }, n;
string s[3];
int solve(int idx, int up, int down) {
	if (idx >= n)
		return 1;
	int &ret = dp[idx][up][down];
	if (ret != -1)
		return (ret % mod);
	ret = 0;
	if (s[1][idx] == s[2][idx]) {
		lp(i,1,3)
		{
			if (i != up && i != down)
				ret += solve(idx + 1, i, i);
			if (ret >= mod)
				ret %= mod;
		}
	} else {
		lp(i,1,3)
		{
			lp(j,1,3)
			{
				if (i != up && j != down && i != j)
					ret += solve(idx + 2, i, j);
				if (ret >= mod)
					ret %= mod;
			}
		}
	}
	return ret;
}
int main() {
#ifdef ONLINE_JUDGE
	FAST
#endif
	cin >> n >> s[1] >> s[2];
	clr(dp, -1);
	cout << solve(0, 0, 0) << "\n";
	return 0;
}