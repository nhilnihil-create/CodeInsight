#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
const ll INF=1e9+7;
const ll N = 52;
ll n;

int main(){
	cin>>n;
	ll w=0;
	ll f=1e9+1;;
	FOR(i,1,n+1){
		w+=i;
		if(w>=n){
			f=i;
			break;
		}
	}
	FOR(i,1,n+1){
		if(i==w-n)continue;
		cout<<i<<endl;
		if(i==f)break;
	}
	return 0;
}
