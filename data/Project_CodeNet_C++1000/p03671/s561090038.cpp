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
	int ar[3];
	for (int i = 0; i < 3; i++)
		cin >> ar[i];
	sort(ar, ar + 3);
	cout << ar[0] + ar[1];
}