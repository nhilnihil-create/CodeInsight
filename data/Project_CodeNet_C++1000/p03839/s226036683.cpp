#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;

int main(){
	int n,k;
	cin >> n >> k;
	vector<ll> da(n);
	rip(i,n,0){
		cin >> da[i];
	}
	ll w=0,b=0;
	rip(i,n,0){
		if(da[i]>0){
			w+=da[i];
			b+=da[i];
		}
	}
	rip(i,k,0){
		if(da[i]>0){
			w-=da[i];
		}
		else{
			b+=da[i];
		}
	}
	ll ans=max(b,w);
	rip(i,n,k){
		if(da[i]>0){
			w-=da[i];
		}
		else{
			b+=da[i];
		}
		if(da[i-k]>0){
			w+=da[i-k];
		}
		else{
			b-=da[i-k];
		}
		ans=max(ans,max(b,w));
	}
	cout << ans << endl;
}