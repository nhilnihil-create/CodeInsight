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
const int N = 1e5 + 5, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
int DP[N][2][2][2][2][2] = { };
string s, ss;
inline bool check(int idx, int prv, int nxt, int cur) {
	if (cur == 0 && s[idx] == 'o' && prv == nxt)
		return true;
	if (cur == 1 && s[idx] == 'o' && prv != nxt)
		return true;
	if (cur == 0 && s[idx] == 'x' && prv != nxt)
		return true;
	if (cur == 1 && s[idx] == 'x' && prv == nxt)
		return true;
	return false;
}
int solve(int idx, int s0, int sn, int s1, int prv, int prvprv) {
	//cout << idx << "\n";
	if (idx >= (int) s.size())
		return true;
	int &ret = DP[idx][s0][sn][s1][prv][prvprv];
	if (ret != -1)
		return ret;
	ret = 0;
	if (idx == (int) s.size() - 1) {
		if (check(idx - 1, prvprv, sn, prv) && check(idx, prv, s0, sn)
				&& check(0, sn, s1, s0))
			ret |= solve(idx + 1, s0, sn, s1, sn, prv);
		return ret;
	}
	if (check(idx - 1, prvprv, 0, prv))
		ret |= solve(idx + 1, s0, sn, s1, 0, prv);
	if (check(idx - 1, prvprv, 1, prv))
		ret |= solve(idx + 1, s0, sn, s1, 1, prv);
	return ret;
}

void out(int idx, int s0, int sn, int s1, int prv, int prvprv) {
	if (idx >= (int) s.size())
		return;
	int &ret = DP[idx][s0][sn][s1][prv][prvprv];
	if (idx == (int) s.size() - 1) {
		if (ret == solve(idx + 1, s0, sn, s1, sn, prv)) {
			if (sn == 0)
				ss.pb('S');
			else
				ss.pb('W');
			out(idx + 1, s0, sn, s1, sn, prv);
		}
	} else if (ret == solve(idx + 1, s0, sn, s1, 0, prv)) {
		ss.pb('S');
		out(idx + 1, s0, sn, s1, 0, prv);
	} else if (ret == solve(idx + 1, s0, sn, s1, 1, prv)) {
		ss.pb('W');
		out(idx + 1, s0, sn, s1, 1, prv);
	}
}
int main() {
#ifdef ONLINE_JUDGE
	FAST
#endif
	int n;
	clr(DP, -1);
	cin >> n >> s;
	lp(i,0,1)
	{
		lp(j,0,1)
		{
			lp(k,0,1)
			{
				int ans = solve(2, i, j, k, k, i);
				//cout << "\n-----------\n";
				if (ans) {
					if (i == 0)
						cout << 'S';
					else
						cout << "W";
					if (k == 0)
						cout << 'S';
					else
						cout << "W";
					out(2, i, j, k, k, i);
					f(ss);
				}
			}
		}
	}
	f(-1);
	return 0;
}