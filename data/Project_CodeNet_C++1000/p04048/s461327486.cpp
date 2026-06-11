#include <cstdio>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	if(!b) return a;
	return gcd(b, a % b);
}

int main(){
	ll a, b; scanf("%lld%lld", &a, &b);
	printf("%lld\n", 3LL * gcd(a, b) * (a / gcd(a, b) - 1LL));
	return 0;
}