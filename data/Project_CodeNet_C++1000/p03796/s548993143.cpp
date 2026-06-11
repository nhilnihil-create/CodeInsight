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
	int n;
	ll fac=1;
	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		fac *= i;
		fac %= (1000000007);
	}
	cout << fac;
}