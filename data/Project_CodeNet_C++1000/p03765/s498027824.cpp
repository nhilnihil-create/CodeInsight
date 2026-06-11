#include <bits/stdc++.h>

using namespace std;

string s,t;
int q;
int p[3][100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> t;
	for (int i=0;i<s.size();i++)
		p[1][i+1] = p[1][i] + ((s[i] == 'A') ? 1 : -1);
	for (int i=0;i<t.size();i++)
		p[2][i+1] = p[2][i] + ((t[i] == 'A') ? 1 : -1);
	cin >> q;
	while(q--)
	{
		int l1,r1,l2,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int a = ((p[1][r1] - p[1][l1-1])%3 + 3)%3;
		int b = ((p[2][r2] - p[2][l2-1])%3 + 3)%3;
		cout << ((a == b) ? "YES\n" : "NO\n");
	}
}