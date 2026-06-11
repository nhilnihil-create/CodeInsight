#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	string s;
	cin >> s;
	string t;
	for (int i = 0; i < string("YAKI").size(); i++) t += s[i];
	if (t == "YAKI") cout << "Yes" << endl;
	else cout << "No" << endl;
}
