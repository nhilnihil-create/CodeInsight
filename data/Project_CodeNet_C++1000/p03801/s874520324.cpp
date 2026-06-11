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
#include <unordered_map>
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
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

const double EPS = 1e-9;

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, 0, N)cin >> A[i];

	vector<pii> DP;

	int h = -1;
	rep(i, 0, N)
	{
		if (chmax(h, A[i]))
		{
			DP.push_back(mp(A[i], i));
		}
	}

	vector<int> MC(N + 1, 0);
	vector<int> IC(N + 1, 0);

	rep(i, 0, N)
	{
		int idx = lower_bound(all(DP), mp(A[i], INF)) - DP.begin();
		MC[0]++;
		MC[idx]--;
		int d = 0;
		if (idx > 0)d = DP[idx - 1].first;
		IC[idx] += A[i] - d;
	}

	rep(i, 1, N + 1)
	{
		MC[i] += MC[i - 1];
	}

	vector<int> ANS(N, 0);
	rep(i, 0, SZ(DP))
	{
		if (DP[i].second == INF)break;
		int d = 0;
		if (i > 0)d = DP[i - 1].first;
		ANS[DP[i].second] += IC[i] + MC[i] * (DP[i].first - d);
	}

	rep(i, 0, N)
	{
		cout << ANS[i] << endl;
	}
	
	return 0;
}