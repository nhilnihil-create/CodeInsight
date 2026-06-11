#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,l,a[100010];
	cin>>n>>l;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n-1;i++){
		ll now=a[i]+a[i+1];
		if(now<l){
			continue;
		}
		cout << "Possible"<<endl;
		for(ll j=0;j<n;j++){
			if(j==i){
				break;
			}
			cout << j+1<<endl;
		}
		for(ll j=n-1;j>i;j--){
			cout << j<<endl;
		}
		return 0;
	}
	cout << "Impossible"<<endl;
	// your code goes here
	return 0;
}