/*https://atcoder.jp/contests/abc059/tasks/abc059_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	// long long m = 1e9;
	string a, b;
	cin >> a >> b;
	// a % m, b % m;
	if (a.length() != b.length())
	{
		if (a.length() > b.length())
			cout << "GREATER";
		else if (a.length() < b.length())
			cout << "LESS";
	}
	else if (a.length() == b.length())
	{
		if (a > b)
			cout << "GREATER";
		else if (a < b)
			cout << "LESS";
		else if (a == b)
			cout << "EQUAL";
	}
}