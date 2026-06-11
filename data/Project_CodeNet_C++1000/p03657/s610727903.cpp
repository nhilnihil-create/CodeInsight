//#include "stdafx.h"
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
	if ((a + b) % 3 == 0)
		cout << "Possible";
	else if(a % 3==0)
		cout << "Possible";
	else if (b % 3 == 0)
		cout << "Possible";
	else
		cout << "Impossible";
}