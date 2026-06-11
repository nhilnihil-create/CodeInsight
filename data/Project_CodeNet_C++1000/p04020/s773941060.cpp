#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 
ll a[100010];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		a[i]=now;
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans+=a[i]/2;
		if(a[i]%2!=0){
			if(a[i+1]!=0){
				ans++;
				a[i+1]--;
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}