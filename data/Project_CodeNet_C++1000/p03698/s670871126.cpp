#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
	string s;
	vector<int> v(26, 0);
	cin >> s;

	rep(i, s.size())
	{
		v[s[i] - 'a']++;
	}
	rep(i, v.size())
	{
		if (v[i] > 1)
		{
			cout << "no" << endl;
			return (0);
		}
	}
	cout << "yes" << endl;
	return (0);
}
