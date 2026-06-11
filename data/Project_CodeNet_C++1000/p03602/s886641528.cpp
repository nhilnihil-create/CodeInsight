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
const int N = 4e2 + 10, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
ll original[N][N] = { }, SP[N][N] = { }, n, d[N][N] = { }, fa[N][N];
int main() {
#ifdef ONLINE_JUDGE
	FAST
#endif
	cin >> n;
	lp(i,1,n)
	{
		lp(j,1,n)
		{
			cin >> original[i][j];
			SP[i][j] = original[i][j];
			if (i == j) {
				if (SP[i][j])
					f(-1);
			}
		}
	}
	lp(k,1,n)
	{
		lp(i,1,n)
		{
			lp(j,1,n)
				SP[i][j] = min(SP[i][j], SP[i][k] + SP[k][j]);
		}
	}
	lp(k,1,n)
	{
		lp(i,1,n)
		{
			lp(j,i,n)
			{
				if (original[i][j] != SP[i][j])
					f(-1);
				if (SP[i][j] == SP[i][k] + SP[k][j] && k != i && k != j)
					fa[i][j] = 1;
			}
		}
	}
	ll sum = 0;
	lp(i,1,n)
		lp(j,i+1,n)
			if (!fa[i][j])
				sum += SP[i][j];
	f(sum);
	return 0;
}