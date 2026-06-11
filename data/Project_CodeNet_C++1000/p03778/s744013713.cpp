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
	int w, a, b;
	cin >> w >> a >> b;
	if ((b > (a + w) && (b + w) > a) || (b < a && (b + w) < (a + w)))
		cout << min(abs((a + w) - b), abs((w + b) - a));
	else
		cout << "0";
}