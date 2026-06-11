#include<cstdio>
using namespace std;

typedef long long ll;

ll solve(ll a, ll b){
	if (!a || !b) return -a - b;
	if (a > b)
		return a / b * b * 2 + solve(a % b, b);
	else if (a < b)
		return b / a * a * 2 + solve(a, b % a);
	else
		return a;
}

int main(){
	ll N, X;
	scanf("%lld %lld", &N, &X);
	printf("%lld", N + solve(N - X, X));
	return 0;
}