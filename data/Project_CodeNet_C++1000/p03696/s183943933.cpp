#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int N;
	string S;
	cin >> N >> S;
	string ans;
	int L = 0, R = 0;
	for (int i = 0; S[i]; i++)
	{
		if (S[i] == ')' && L == 0)
			R++;
		if (S[i] == ')' && L != 0)
			L--;
		if (S[i] == '(')
			L++;
	}
	for (int i = 0; i < R; i++)
		ans += '(';
	ans += S;
	for (int i = 0; i < L; i++)
		ans += ')';
	cout << ans << endl;
}

