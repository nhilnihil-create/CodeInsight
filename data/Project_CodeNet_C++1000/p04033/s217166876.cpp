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
	int a, b;
	cin >> a >> b;
	string ans;
	if (a > 0 && b > 0)
		ans = "Positive";
	else if (a <= 0 && b >= 0)
		ans = "Zero";
	else if ((b-a) % 2 == 0)
		ans = "Negative";
	else
		ans = "Positive";
	cout << ans << endl;
}

