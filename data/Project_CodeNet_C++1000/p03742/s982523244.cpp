#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long x,y;
	cin >> x >> y;
	cout << (abs(x-y) <= 1 ? "Brown" : "Alice") << endl;
	return 0;
}
