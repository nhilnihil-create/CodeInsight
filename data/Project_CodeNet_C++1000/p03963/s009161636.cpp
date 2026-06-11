#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ll n, k; scanf("%lld %lld", &n, &k);

	printf("%lld", k * (ll)powl(k - 1, n - 1));

	return 0;

}