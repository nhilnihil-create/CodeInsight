#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;

typedef long long ll ;
#define rep(i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	
	cin >> N >> K;

	ll a[N];
	ll vr[N+1];
	ll v[N+1];
	v[0] = vr[0] = 0;
	rep(i, N)
	{
		cin >> a[i];
		v[i+1] = v[i] + a[i];
		if (a[i] >= 0)
		{
			vr[i+1] = vr[i] + a[i];
		}
		else
		{
			vr[i+1] = vr[i];
		}
	}

	ll ans = 0;

	rep(i, N - K + 1)
	{
		//ans = max(ans, vr[i] + vr[N] - vr[i+K]);
		ans = max(ans, max(v[i+K]- v[i], 0ll) + vr[i] + vr[N] - vr[i+K]);
	}

	cout << ans << endl;



	
	return 0;
}
