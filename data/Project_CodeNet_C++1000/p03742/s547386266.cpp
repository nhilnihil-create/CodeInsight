#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll g(ll p) {return p > 0 ? p : -p;}
int main()
{
	ll x, y;
	cin >> x >> y;
	cout << (g(x - y) <= 1 ? "Brown" : "Alice");
    return 0;
}
