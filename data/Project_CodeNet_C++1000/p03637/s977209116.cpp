#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

ll cnt_odd=0;
ll cnt_4=0;
ll cnt=0;
rep(i,N){
	ll a;
	cin>>a;
	if(a%2) cnt_odd++;
	else if(a%4==0) cnt_4++;
	else cnt++;
}

if(cnt==0){
if(cnt_odd>cnt_4+1) cout<<"No"<<endl;
else cout<<"Yes"<<endl;
}
else{
if(cnt_odd>cnt_4) cout<<"No"<<endl;
else cout<<"Yes"<<endl;
}


}
	
