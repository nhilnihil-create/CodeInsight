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

	string S, T;
	cin >> S >> T;
	int Q;
	cin >> Q;

	vector<vector<int>> IMOS(2);
	IMOS[0].push_back(0), IMOS[1].push_back(0);

	rep(i, 0, SZ(S))
	{
		IMOS[0].push_back(IMOS[0][i]);
		if (S[i] == 'A')IMOS[0][i + 1]++;
		else IMOS[0][i + 1] += 2;
	}
	rep(i, 0, SZ(T))
	{
		IMOS[1].push_back(IMOS[1][i]);
		if (T[i] == 'A')IMOS[1][i + 1]++;
		else IMOS[1][i + 1] += 2;
	}

	int a, b, c, d;
	rep(i, 0, Q)
	{
		cin >> a >> b >> c >> d;
		a--, c--;
		if ((IMOS[0][b] - IMOS[0][a]) % 3 == (IMOS[1][d] - IMOS[1][c]) % 3)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}
