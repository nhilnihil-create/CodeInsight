#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef long long ll;
ll n,A[1000050];
int main(){
	cin >> n;
	A[1] = n; A[1] %= mod;
	ll ans = A[1];
	for(ll i = 2; i<=n; i++){
		A[i] = A[i-1];
		A[i]%=mod;
		A[i] += ((n-1)*(n-1))%mod;
		A[i]%=mod;
		if(2 <= i-2) A[i] += ans-A[i-1]-A[i-2];
		A[i] %= mod;
		A[i] += n-max((ll)2, i-1)+1; 
		A[i]%=mod;
		A[i]+=mod;
		A[i]%=mod;
		ans += A[i];
		ans %= mod;
	}
	cout << A[n];
}
/*
f(x) =
case: 1____
f(x-1)
case: YXX.. X!=1, Y!=1
(n-1)^2
case: Y111__, x-Y-1 > 0
f(x-Y-1) from Y=2 to Y=x-2, hence f(x-3) to f(1)
case: Y111.., x-1 <= Y
Y can vary from Y=2 to x-2 and from x-1 to N
hence N-x+2
*/
