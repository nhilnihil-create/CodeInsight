#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[100010];
int main() {
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		a[x]++;
		a[y]++;
	}
	bool ch=true;
	for(ll i=0;i<n;i++){
		if(a[i]%2!=0){
			ch=false;
		}
	}
	cout << (ch?"YES":"NO");
	// your code goes here
	return 0;
}