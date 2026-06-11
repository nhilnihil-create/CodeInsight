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
	int a, b;
	cin >> a >> b;
	if(a==b)
		cout << "Draw";
	else if (a == 1)
		cout << "Alice";
	else if(b == 1)
		cout << "Bob";
	else
	{
		if (a > b)
			cout << "Alice";
		else if (b > a)
			cout << "Bob";
	}
}
