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

	int n;
	cin >> n;

	int p[n+1];
	rep(i,n) cin >> p[i+1];

	int ans = 0;

	FOR(i,1,n){
		if(i == p[i]){
			swap(p[i],p[i+1]);
			ans++;
		}
	}

	if(n == p[n]) {
		swap(p[n-1],p[n]);
		ans++;
	}

	cout << ans << endl;
}