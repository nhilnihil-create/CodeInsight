#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll k;
	cin >> k;

	
	ll n = 50;
	cout << n << endl;

	ll a = k / n - k % n + n - 1;
	// 最終的に数列のすべての項がn-1となる
	rep(i,n) cout << (i < k % n ? a + n + 1 :  a) << " "; 
	cout << endl;
}