#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll a[100010];
int main() {
	ll n;
	cin>>n;
	ll cnt=1;
	ll ans=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==cnt){
			cnt++;
		}
		else if(a[i]>cnt){
			if(a[i]%cnt==0){
				ans+=a[i]/cnt-1;
			}
			else{
				ans+=a[i]/cnt;
			}
		}
		if(cnt==1){
			cnt++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}