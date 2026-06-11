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

ll N,L;
ll a[100010];
int main(){
    cin>>N>>L;
	ll last=-1;
	for(ll i=0;i<N;i++){
		cin>>a[i];
	}
	for(ll i=0;i<N-1;i++){
		if(a[i]+a[i+1]>=L)last=i;
	}
	if(last==-1){
		cout<<"Impossible"<<endl;return 0;
	}
	cout<<"Possible"<<endl;
	for(ll i=0;i<last;i++){
		cout<<i+1<<endl;
	}
	for(ll i=N-2;i>last;i--){
		cout<<i+1<<endl;
	}
	cout<<last+1<<endl;	
    return 0;
}