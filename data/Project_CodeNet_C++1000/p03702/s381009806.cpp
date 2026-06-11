#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = (B-1); I >= (A); --I)
const ll INF=1e18+7;
const ll MOD=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,a,b;
	cin >> n >> a >> b;
	vector<ll> h(n);
	FOR(i,0,n)cin>>h[i];
	ll l = 0, r = MOD;

	while(r-l>1){
		ll mid = (l+r)/2;
		ll answ=0;



		FOR(i,0,n)if(h[i]>mid*b){
			answ += (h[i]-mid*b)/(a-b);
			if((h[i]-mid*b)%(a-b)!=0)answ++;
		}



		if(answ<=mid){
			r = mid;
		}else{
			l = mid;
		}
	}

	cout << l+1 << endl;
}