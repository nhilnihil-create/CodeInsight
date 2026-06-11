#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll x, y; cin >> x >> y;
	if (abs(x - y) < 2)cout << "Brown";
	else cout << "Alice";
	cout << endl;
	return 0;
}