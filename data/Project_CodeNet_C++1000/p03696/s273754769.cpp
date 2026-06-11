#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main(void)
{
	int n;
	int rsum, lsum;
	int tmp;
	string s;

	cin >> n >> s;
	lsum = rsum = 0;
	rep(i, n)
	{
		if (s[i] == ')')
		{
			if (rsum > 0)
				rsum--;
			else
				lsum++;
		}
		else
			rsum++;
	}
	rep(i, lsum)
		cout << '(';
	cout << s;
	rep(i, rsum)
		cout << ')';
	cout << endl;
	return 0;
}
