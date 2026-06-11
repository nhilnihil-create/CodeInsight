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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ru1 = a*b;
	ll ru2 = c*d;
	cout << max(ru1, ru2);
}