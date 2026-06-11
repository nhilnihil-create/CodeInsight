#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n);
using namespace std;
int main()
{
	MaRiaMa;
	int n,k=0;
	cin >> n;
	vi p(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'I')
		{
			k++;
			p[i] = k;
		}
		else
		{
			k--;
			p[i] = k;
		}
	}
	sort(p.begin(), p.end(),greater<int>());
	if (p[0] > -1)
		cout << p[0];
	else
		cout << "0";
}