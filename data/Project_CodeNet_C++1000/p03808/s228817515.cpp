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
ll N;
ll a[100010];
ll differ[100010];
bool Check(ll n){
	for(ll i=0;i<N;i++){
		if( (n-differ[i])%N !=0 ){
			return false;
		}
	}
	return true;
}
int main(){
    cin>>N;
	ll sum=0;
	for(ll i=0;i<N;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(ll i=0;i<N-1;i++){
		differ[i]=a[i+1]-a[i];
	}
	differ[N-1]=a[0]-a[N-1];

	ll sum1_N=N*(N+1)/2;
	if(sum%(sum1_N)!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	ll cnt=0;
	for(ll i=0;i<N;i++){
		if(differ[i]-sum/sum1_N>0){
			cout<<"NO"<<endl;
			return 0;
		}
		if((sum/sum1_N-differ[i])%N==0){
			cnt+=(sum/sum1_N-differ[i])/N;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(cnt!=sum/sum1_N){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
    return 0;
}