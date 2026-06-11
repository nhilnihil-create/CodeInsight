#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define print(n) cout<<n<<endl
#define rep(i,a,n) for(ll i=a;i<n;i++)
int main() {
	int a,b,c,d;
	cin>>a>>b>>c;
	d=max({a,b,c});
	print(a+b+c-d);
}