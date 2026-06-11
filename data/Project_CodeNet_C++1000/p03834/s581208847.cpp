#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Inf = 1e9+7;
const int Mod = 1e9+7;

int main ()
{
	string x;
	cin >> x;
	for (int i = 0 ; i < x.size(); i++) {
		if (x[i]==',')cout <<" ";
		else cout << x[i];
	}
	cout << endl;
	return 0;
}
