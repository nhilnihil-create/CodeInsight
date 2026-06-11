#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll a[20001],b[20001];

int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		a[i]=1+20000*i;
		b[i]=1+(n-1)*20000+(-20000)*i;
	}
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		x--;
		a[x]+=i;
	}
	for(ll i=0;i<n;i++,cout << (i==n?"\n":" ")){
		cout << a[i];
	}
	for(ll i=0;i<n;i++,cout<< (i==n?"\n":" ")){
		cout << b[i];
	}
	// your code goes here
	return 0;
}