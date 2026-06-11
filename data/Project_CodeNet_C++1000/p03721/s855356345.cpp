#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n,k;cin>>n>>k;


	map<ll,ll> mp;

	rep(i,n){
		int a, b; cin>>a>>b;

		if(mp[a] <=k){mp[a] += b;}
	}



	for(auto e: mp){
		k -=e.second;

		if(k <=0){
			writeln(e.first);
			return 0;
		}
	}
}
