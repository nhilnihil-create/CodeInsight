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
	int n,i=1;
	cin >> n;
	while (pow(2, i) <= n)
	{
		i++;
	}
	cout << pow(2, i - 1);
}