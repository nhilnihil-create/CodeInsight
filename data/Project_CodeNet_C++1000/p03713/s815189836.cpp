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

	int H, W;
	cin >> H >> W;

	int ans = INF;

	int A[3] = { 0 };
	
	rep(i, 1, H)
	{
		if (i + 1 < H)
		{
			A[0] = i * W;

			if ((H - i) % 2 == 0)
			{
				A[1] = A[2] = (H - i) / 2 * W;
			}
			else
			{
				A[1] = (H - i) / 2 * W;
				A[2] = (H - i + 1) / 2 * W;
			}
			sort(A, A + 3);
			chmin(ans, A[2] - A[0]);
		}

		A[0] = i * W;

		if (W % 2 == 0)
		{
			A[1] = A[2] = W / 2 * (H - i);
		}
		else
		{
			A[1] = W / 2 * (H - i);
			A[2] = (W + 1) / 2 * (H - i);
		}

		sort(A, A + 3);
		chmin(ans, A[2] - A[0]);
	}

	rep(j, 1, W)
	{
		if (j + 1 < W)
		{
			A[0] = j * H;

			if ((W - j) % 2 == 0)
			{
				A[1] = A[2] = (W - j) / 2 * H;
			}
			else
			{
				A[1] = (W - j) / 2 * H;
				A[2] = (W - j + 1) / 2 * H;
			}
			sort(A, A + 3);
			chmin(ans, A[2] - A[0]);
		}

		A[0] = j * H;

		if (H % 2 == 0)
		{
			A[1] = A[2] = H / 2 * (W - j);
		}
		else
		{
			A[1] = H / 2 * (W - j);
			A[2] = (H + 1) / 2 * (W - j);
		}

		sort(A, A + 3);
		chmin(ans, A[2] - A[0]);
	}

	cout << ans << endl;

	return 0;
}