#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ll n, a, b;
	scanf("%lld%lld%lld", &n, &a, &b);
	if (n == 1 && a == b)
		return printf("1\n"), 0;
	else if (n == 1 && a != b)
		return printf("0\n"), 0;
	if (b < a)
		return printf("0\n"), 0;

	printf("%lld\n", (b - a) * (n - 2) + 1);
}
