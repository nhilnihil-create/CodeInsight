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

	ll N, A, B, C, D;
	
	cin >> N >> A >> B >> C >> D;

	ll r = B - A;
	bool re = false;

	rep(i, N)
	{
		ll left = C * (N-1-i) - D * i;
		ll right = D * (N-1-i) - C * i;
		if ((left <= r) && (r <= right))
		{
			re = true;
			break;			
		}
	}

	if (re)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}
