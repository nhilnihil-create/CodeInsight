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
	int a, b, c;
	cin >> a >> b >> c;
	multiset<int> p;
	p.insert(a); p.insert(b); p.insert(c);
	int n= max({ p.count(a), p.count(b), p.count(c) });
	if (n == 1)
		cout << "3";
	else if (n == 3)
		cout << "1";
	else
		cout << n;
}