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
const int nn = 1e6 + 15;
int dx[8] = { -1, 0, 0, 1, 1, -1, 1, -1 };
int dy[8] = { 0, -1, 1, 0, 1, -1, -1, 1 };


int main()
{
	fast();
	string s;
	cin >> s;
	int n = sz(s);
	int a = -1, b = -1;
	vector<int> arr[30];
	for (int i = 0; i < n; i++)
	{
		arr[s[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < sz(arr[i]); j++)
		{
			for (int k = j+1, x = 2; k < sz(arr[i]); k++,x++)
			{
				if (x>(arr[i][k] - arr[i][j]+1)/2)
				{
					a = arr[i][j] + 1;
					b = arr[i][k] + 1;
					break;
				}
			}
			if (a != -1)
				break;
		}
		if (a != -1)
			break;
	}
	if (a != -1)
		cout << a << " " << b << endl;
	else
		cout << a << " " << b << endl;
	//system("pause");
	return 0;
}