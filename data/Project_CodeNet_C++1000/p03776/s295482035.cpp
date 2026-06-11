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

int COM(int n, int k) {
	int r = 1;
	for (int d = 1; d <= k; ++d) {
		r *= n--;
		r /= d;
	}
	return r;
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, A, B;
	int V[100];
	map<int, int> vmap;

	cin >> N >> A >> B;
	rep(i, 0, N)
	{
		cin >> V[i];
		vmap[V[i]]++;
	}

	sort(V, V + N, greater<int>());

	double ansv = 0.0;
	int cnt = 0;
	int pv = -1;
	rep(i, 0, A)
	{
		ansv += (double)V[i];
		if (V[i] != pv)
		{
			cnt = 1;
		}
		else
		{
			cnt++;
		}
		pv = V[i];
	}
	ansv /= A;

	int ansc;
	if (cnt != A)
	{
		ansc = COM(vmap[pv], cnt);
	}
	else
	{
		ansc = 0;
		rep(i, A, min(B + 1, vmap[pv] + 1))
		{
			ansc += COM(vmap[pv], i);
		}
	}

	cout << fixed << setprecision(12) << ansv << endl << ansc << endl;

	return 0;
}