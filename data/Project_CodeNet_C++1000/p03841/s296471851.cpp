#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <cstring>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 0.5;
const LL INF = 1e9;
const LL mod = 1000003;
const LL LINF = 1e18 + 10;
const LL MAX = 1e5 + 1;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n;
	cin >> n;
	VI x(n + 1);
	VI a(n*n + 1, -1);
	FOR(i, 0, n)
		cin >> x[i + 1];

	FOR(i, 1, n + 1)
		a[x[i]] = i;

	bool mozhna = 1;
	VI treba(n + 1, 0);
	FOR(i, 1, n + 1)
		treba[i] = i - 1;

	VPII now(n + 1);
	set<PII> kr;
	
	FOR(i, 1, n + 1)
		now[i] = MP(x[i] - i - 1, i), kr.insert(now[i]);

	VI totake(n + 1, 0);

	FOR(i, 1, n*n + 1)
	{
		if (a[i] != -1)
		{
			kr.erase(now[a[i]]);
			treba[a[i]] = 0;
			totake[a[i]] = n - a[i];
			continue;
		}

		PII del;
		bool fkag = 0;

		for (auto j : kr)
			if (treba[j.Y])
			{
				--treba[j.Y];
				a[i] = j.Y;
				del = j;
				fkag = 1;
				break;
			}

		if (fkag)
		{
			kr.erase(del);
			del.X++;
			kr.insert(del);
			now[del.Y].X++;
			continue;
		}

		FOR(j, 1, n + 1)
			if (totake[j])
			{
				totake[j]--;
				a[i] = j;
				break;
			}
	}

	FOR(i, 1, n + 1)
		if (treba[i])
			mozhna = 0;

	FOR(i, 1, n*n + 1)
		if (a[i] == -1)
			mozhna = 0;

	FOR(i, 1, n + 1)
		if (totake[i])
			mozhna = 0;

	if (!mozhna)
	{
		cout << "No";
		return 0;
	}

	cout << "Yes" << endl;
	FOR(i, 1, 1 + n * n)
		cout << a[i] << " ";

	cin >> n;
	return 0;
}