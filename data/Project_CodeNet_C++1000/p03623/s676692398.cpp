#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int x, a, b;
	cin >> x >> a >> b;
	int xa, xb;
	if (x - a < 0)xa = (x - a) * -1;
	else xa = x - a;
	if (x - b < 0) xb = (x - b) * -1;
	else xb = x - b;
	if (xa < xb)cout << "A" << endl;
	else cout << "B" << endl;
}