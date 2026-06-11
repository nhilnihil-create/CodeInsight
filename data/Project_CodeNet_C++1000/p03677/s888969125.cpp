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
#include<unordered_map>
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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
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

	int N, M;
	cin >> N >> M;

	vector<multiset<int>> IMOS(M + 3);
	vector<int> A(N);
	int asum = 0;
	rep(i, 0, N)
	{
		cin >> A[i];
		A[i]--;
		if (i > 0)
		{
			if (A[i] < A[i - 1])
			{
				asum += M - 1 - A[i - 1] + A[i] + 1;
			}
			else
			{
				asum += A[i] - A[i - 1];
			}

			if ((A[i - 1] + 1) % M == A[i])continue;

			int ta = (A[i - 1] + 2) % M;

			IMOS[ta].insert(1);

			if (A[i] < ta)
			{
				IMOS[0].insert(M - 1 - ta + 2);
				IMOS[A[i] + 1].insert(-(M - 1 - ta + 1 + A[i] + 2));
				//cout << "a" << endl;
			}
			else
			{
				IMOS[A[i] + 1].insert(-(A[i] - ta + 2));
				//cout << "b" << endl;
			}
		}
	}

	int ans = 0;
	int sum = 0;
	int cnt = 0;
	rep(i, 0, M)
	{
		for (auto v : IMOS[i])
		{
			sum += v;
			if (v > 0)cnt++;
			else cnt--;
		}
		chmax(ans, sum);
		sum += cnt;
	}

	ans = asum - ans;

	cout << ans << endl;

	return 0;
}