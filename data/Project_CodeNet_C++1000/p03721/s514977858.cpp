#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
ll n,k;
pair<ll,ll> a[100005];
ll cnt;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i].fi>>a[i].se;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cnt+=a[i].se;
		if(cnt>=k){
			cout<<a[i].fi;
			re 0;
		}
	}
	re 0;
}