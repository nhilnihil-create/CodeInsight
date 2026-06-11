#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

set<ll> s;
int n;

void go(int x, ll now){
	if(x>n){
		if(now>0) s.insert(now);
	}
	else go(x+1,now),go(x+1,now-x),go(x+1,now+x);
}

int main(){FIN;
	ll n; cin>>n;
	ll l=1,r=1e9;
	while(l<=r){
		ll m=(l+r)/2;
		if(m*(m+1)/2>=n) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
	
	go(1,0);
	for(auto x:s)cout<<x<<" ";cout<<"\n";
}