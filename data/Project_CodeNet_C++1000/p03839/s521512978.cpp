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
ll a[100010];
ll plusSum=0;
int main(){
    cin>>N>>K;
    for(ll i=0;i<N;i++){
		cin>>a[i];
		if(a[i]>0){
			plusSum+=a[i];
		}
    }
	ll ans=0;
	ll l=0,r=K;
	ll minusSum=0;
	for(ll i=l;i<r;i++){
		if(a[i]<0){
			minusSum+=a[i];
		}
	}
	while(r<=N){
		while(a[r]>=0 && r<=N){
			r++;
		}
		while(r-l>=K){
			ans=max(ans,plusSum+minusSum);
			if(a[l]<0){
				minusSum-=a[l];
			}
			l++;
		}
		if(r==N)break;
		minusSum+=a[r];
		r++;
	}
	l=0;r=K;
	minusSum=0;
	for(ll i=l;i<r;i++){
		if(a[i]>0){
			minusSum+=a[i];
		}
	}
	while(r<=N){
		while(a[r]<0 && r<=N){
			r++;
		}
		while(r-l>=K){
			ans=max(ans,plusSum-minusSum);
			if(a[l]>0){
				minusSum-=a[l];
			}
			l++;
		}
		if(r==N)break;
		minusSum+=a[r];
		r++;
	}
	cout<<ans<<endl;
    return 0;
}