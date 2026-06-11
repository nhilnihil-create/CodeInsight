#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 10000000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n,ans=1;cin>>n;
	vector<ll> t(n),a(n+1,0),res(n,0);

	cin>>t[0];
	res[0]=t[0];

	for(int i=1;i < n;i++)
	{
		cin>>t[i];
		if(t[i]>t[i-1]){
			res[i]=t[i];
		}
	}

	rep(i,n)cin>>a[i];

	
	for(int i=n-1;0<=i;i--)
	{
		if(a[i]>a[i+1]){
			if((!res[i] && a[i]<=t[i])|| (res[i] && res[i]==a[i])){
				res[i]=a[i];//
			}else {
				ans*=0;
			}
		}
	}
	//rep(i,n)cout<<res[i]<<endl;

	rep(i,n){
		if(!res[i]){
			ans*=min(a[i],t[i]);
			ans%=mod;
		}
	}
	cout<<ans<<endl;
}