#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,K;
ll a[100010],b[100010];
int main(){
    cin>>N>>K;
	ll maxA=0;
    for(ll i=0;i<N;i++){
		cin>>a[i]>>b[i];
		maxA=max(maxA,a[i]);
    }
	ll maxBit=0;
	for(ll i=0;(1<<i)<=maxA;i++){
		if((1ll<<i)&maxA)maxBit=i;
	}
	for(ll i=0;(1ll<<i)<=K;i++){
		if((1ll<<i)&K)maxBit=max(maxBit,i);
	}
	ll ans=0;
	for(ll i=0;i<N;i++){
		bool f=true;
		for(ll bit=0;bit<=maxBit;bit++){
			if( ((1ll<<bit)&K)==0 && ((1ll<<bit)&a[i])!=0 ){
				f=false;
				break;
			}
		}
		if(f)ans+=b[i];
	}
	for(ll bit=maxBit;bit>=0;bit--){
		if(((1ll<<bit)&K)==0)continue;
		ll sum=0;
		for(ll i=0;i<N;i++){
			if((1ll<<bit)&a[i])continue;
			bool f=true;
			for(ll j=maxBit;j>bit;j--){
				if( ((1ll<<j)&K)==0 && ((1ll<<j)&a[i])!=0 ){
					f=false;
					break;
				}
			}
			if(f)sum+=b[i];
		}
		ans=max(sum,ans);
	}
	cout<<ans;
    return 0;
}