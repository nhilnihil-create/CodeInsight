#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+6;
int a[N];
ll b[N];
int n; 
ll k;
bool ch(ll x){
	ll ret = 0;
	for(int i=0;i<n;i++){
		if(a[i]<=x)ret+=b[i];
		if(ret>=k)return true;
	}
	return false;
}
void solve(){
	cin>>n>>k; 
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	ll st = 1;
	ll en = 1e5+1;
	while(st<=en){
		ll mid = (st+en)/2;
		if(ch(mid)){
			en = mid-1;
		}
		else{
			st = mid+1;
		}
	}
	cout<<st<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
