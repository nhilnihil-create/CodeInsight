#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if (!a) return 0;
	if (b%a==0) return 2LL*(b/a)*a-a;
    return 2LL*a*(b/a)+gcd(b%a,a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, X;
	cin>>N>>X;
	cout << N+gcd(X,N-X) << endl;
	return 0;
}
