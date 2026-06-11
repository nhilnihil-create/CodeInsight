#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll t[100010],a[100010],T[100010],A[100010];
bool ch[100010];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		t[i]=x;
	}
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		a[i]=x;
	}
	ch[0]=true;ch[n-1]=true;
	for(ll i=1;i<n;i++){
		if(t[i-1]<t[i]){
			ch[i]=true;
			if(t[i]>a[i]){
				cout << 0;
				return 0;
			}
		}
	}
	for(ll i=n-2;i>=0;i--){
		if(a[i]>a[i+1]){
			ch[i]=true;
			if(a[i]>t[i]){
				cout << 0;
				return 0;
			}
		}
	}
	if(t[0]>a[0]){
		cout << 0;
		return 0;
	}
	if(a[n-1]>t[n-1]){
		cout << 0;
		return 0;
	}
	ll ans=1;
	for(ll i=0;i<n;i++){
		if(ch[i]){
	//		cout <<ans<<endl;
			continue;
		}
		ans*=min(t[i],a[i]);
		ans%=inf;
	//	cout << ans<<endl;
	}
	cout <<ans;
	// your code goes here
	return 0;
}