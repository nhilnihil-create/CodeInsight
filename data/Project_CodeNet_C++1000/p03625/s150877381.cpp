#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e18+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N;
map<ll,ll> mp;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

rep(i,N){
	ll a;
	cin>>a;
	mp[a]++;
}

ll square_max=0;
for(auto x:mp) {
	if(x.second>=4) square_max=max(square_max,x.first);
}
ll rec1_max=0;
for(auto x:mp) {
	if(x.second>=2) rec1_max=max(rec1_max,x.first);
}
mp[rec1_max]=0;
ll rec2_max=0;
for(auto x:mp) {
	if(x.second>=2) rec2_max=max(rec2_max,x.first);
}

cout<<max(square_max*square_max,rec1_max*rec2_max)<<endl;

}
	
