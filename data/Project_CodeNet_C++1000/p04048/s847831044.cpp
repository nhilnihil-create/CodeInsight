#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll f(ll a, ll b){
	if(b == 0)return -a;
	return 2*(a/b)*b + f(b, a%b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll n, x;
	cin>>n>>x;
	cout<<n + f(x, n - x)<<endl;

	return 0;
}