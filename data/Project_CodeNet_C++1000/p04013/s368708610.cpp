#define __USE_MINGW_ANSI_STDIO
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long long ull;
typedef pair<int, int> ii;

#define all(v)		((v).begin()), ((v).end())
#define sz(v)		((int)((v).size()))
#define endl		"\n"
#define fx(n)		fixed<<setprecision(n)
#define mk			make_pair	

void fast()
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL);
	cin.tie(NULL);
/*#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("pyramid.in", "r", stdin);
#endif*/
}
const double pi = 2 * acos(0.0);
const ll oo = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int nn = 5e3 + 15;
int dx[8] = { -1, 0, 0, 1, 1, -1, 1, -1 };
int dy[8] = { 0, -1, 1, 0, 1, -1, -1, 1 };

ll dp[55][55][55 * 55];
ll n, a;
int arr[55];
ll solve(int idx, int sum, int cnt = 0)
{
	if (idx == n)
		return sum == a*cnt&&cnt;
	if (dp[idx][cnt][sum] != -1)
		return dp[idx][cnt][sum];
	ll c1 = solve(idx + 1, sum, cnt);
	ll c2 = solve(idx + 1, sum + arr[idx], cnt + 1);
	return dp[idx][cnt][sum] = c1 + c2;
}
int main()
{
	fast();
	cin >> n >> a;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0) << endl;
	//system("pause");
	return 0;
}