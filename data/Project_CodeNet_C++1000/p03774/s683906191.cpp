#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n);
using namespace std;
int p[10000];
int main()
{
	MaRiaMa;
	int n, m,k=0;
	cin >> n >> m;
	vector<pair<int, int>>l(n);
	vector<pair<int, int>>h(m);
	for (int i = 0; i < n; i++)
	{
		cin >> l[i].first >> l[i].second;
	}
	for (int j = 0; j < m; j++)
	{
		cin >> h[j].first >> h[j].second;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
		    p[k] = abs(l[i].first - h[j].first) + abs(l[i].second - h[j].second);
			k++;
		}
		for (int m = 0; m < k; m++)
		{
			if (p[m] == *min_element(p, p+k))
			{
				cout << m + 1<<e;
				break;
			}
		}
		k = 0;
	}
}