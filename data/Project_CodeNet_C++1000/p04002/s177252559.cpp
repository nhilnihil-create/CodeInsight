#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
const ll MOD=1000000007;
int main(){
	ll H,W,N; cin>>H>>W>>N;
	map<P,ll> m;
	rep(i,N){
		ll A,B; cin>>A>>B;
		rep(s,3)rep(t,3){
			if(1<=A-s && A-s<=H-2 && 1<=B-t && B-t<=W-2) m[mp(A-s,B-t)]++;
		}
	}
	vector<ll> ans(10,0);
	for(auto itr=m.bg;itr!=m.ed;itr++){
		ans[itr->b]++;
	}
	ll cnt=0;
	rep1(i,9){
		cnt+=ans[i];
	}
	cout<<(H-2)*(W-2)-cnt<<endl;
	rep1(i,9){
		cout<<ans[i]<<endl;
	}
}