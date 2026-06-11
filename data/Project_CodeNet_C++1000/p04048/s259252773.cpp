#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll f(ll a, ll b){
	if(a>b) swap(a, b);
	if(b%a==0) return (2*(b/a)-1)*a;
	else return 2*a*(b/a)+f(b%a, a);
}

int main(){
	ll n, x;
	cin >> n >> x;
	cout << n+f(x, n-x) << endl;
	return 0;
}