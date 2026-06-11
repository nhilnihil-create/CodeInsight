//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<unordered_set>
#include<bitset>
#include<complex>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD =  (int)1e9 + 7;
const double EPS = 1e-9;

int DP[60][2600];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, A;
	int X[60];

	cin >> N >> A;
	rep(i, 0, N)
	{
		cin >> X[i];
	}

	DP[0][0] = 1;

	rep(k, 0, N)
	{
		rrep(i, 0, N)rrep(j, 0, 2600)
		{
			if (DP[i][j] == INF)continue;
			DP[i + 1][j + X[k]] += DP[i][j];
		}
	}

	int ans = 0;
	rep(i, 1, N + 1)
	{
		if (DP[i][A*i] != INF)
		{
			ans += DP[i][A*i];
		}
	}

	cout << ans << endl;

	return 0;
}