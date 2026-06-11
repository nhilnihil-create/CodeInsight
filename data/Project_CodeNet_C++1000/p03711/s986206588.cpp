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
	int x, y;
	cin >> x >> y;
	set<int >s1 = { 1,3,5,7,8,10,12 }; set<int >s2 = { 4,6,9,11 }; set<int >s3 = { 2 };
	if ((s1.count(x) == 1) && (s1.count(y) == 1))
		cout << "Yes";
	else if ((s2.count(x)) == 1 && (s2.count(y) == 1))
		cout << "Yes";
	else if ((s3.count(x)) == 1 && (s3.count(y) == 1))
		cout << "Yes";
	else
		cout << "No";
}