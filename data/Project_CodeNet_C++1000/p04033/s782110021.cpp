#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	int a, b;
	cin >> a >> b;
	if (a < 0 && 0 < b || a * b == 0) cout << "Zero" << endl;
	else if (0 < a) cout << "Positive" << endl;
	else {
		if ((b - a + 1) % 2 == 0) cout << "Positive" << endl;
		else cout << "Negative" << endl;
	}
}
