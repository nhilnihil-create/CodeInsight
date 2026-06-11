#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
	ll h,w;cin>>h>>w;
	ll ans=INF;

	for(ll i=1;i<h;i++){
		ll MAX=0,MIN=INF;
		MAX=MIN=i*w;

		MAX=max(MAX,(h-i)*((w+(w%2))/2));
		MIN=min(MIN,(h-i)*((w)/2));

		ans=min(ans,MAX-MIN);
	}
	
	for(ll i=1;i<w;i++){
		ll MAX=0,MIN=INF;
		MAX=MIN=i*h;

		MAX=max(MAX,(w-i)*((h+(h%2))/2));
		MIN=min(MIN,(w-i)*((h)/2));

		ans=min(ans,MAX-MIN);
	}


	for(ll i=1;i<h;i++){
		ll MAX=i*w,MIN=i*w;

		MAX=max(MAX,w*((h-i+(h-i)%2)/2));
		MIN=min(MIN,w*((h-i)/2));

		ans=min(ans,MAX-MIN);
	}

	for(ll i=1;i<w;i++){
		ll MAX=i*h,MIN=i*h;

		MAX=max(MAX,h*((w-i+(w-i)%2)/2));
		MIN=min(MIN,h*((w-i)/2));

		ans=min(ans,MAX-MIN);
	}

	cout<<ans<<endl;
	return 0;
}