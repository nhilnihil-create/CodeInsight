#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LL MOD = 1000000007;
const int INF = 1e9;
const LL LINF = 1LL * INF * INF;
const int MAXN = 100007;
const LD EPS = 1e-7;

int n;

int gcd(int a, int b) { return (a ? gcd(b % a, a) : b); }

int solve(vector <int> B)
{
	int cnt = 0, p;
	REP(i, n)
		if (B[i] & 1)
			p = i;
		else
			++cnt;
	if (cnt & 1)
		return 1;
	if (cnt < n - 1 || B[p] == 1)
		return 2;
	--B[p];
	int g = B[0];
	REP(i, n)
		g = gcd(g, B[i]);
	REP(i, n)
		B[i] /= g;
	return 3 - solve(B);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	cin >> n;
	vector <int> A(n);
	REP(i, n)
		cin >> A[i];
	cout << (solve(A) == 1 ? "First" : "Second");
	//cout << endl; system("pause");
	return 0;
}