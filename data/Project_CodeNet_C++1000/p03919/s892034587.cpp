#include "bits/stdc++.h"

using namespace std;

#define rep(n, i) for (int i = 0; i < n; i++)

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void solve()
{
	int H, W;
	cin >> H >> W;
	string s;
	rep(H, i) rep(W, j)
	{
		cin >> s;
		if (s == "snuke")
		{
			cout << alphabet[j] << i + 1 << endl;
			return;
		}
	}
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
