#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 
const ll INF=10e9;

signed main(){
	int n,m; cin>>n>>m;
	vector<pl> p(n);
	vector<pl> q(m);
	vl ans(n);
	rep(i,0,n){
		ll a,b; cin>>a>>b;
		p[i].first=a;
		p[i].second=b;
	}
	rep(i,0,m){
		ll a,b; cin>>a>>b;
		q[i].first=a;
		q[i].second=b;
	}
	rep(i,0,n){
		ll cnt=abs(p[i].first-q[0].first)+abs(p[i].second-q[0].second);
		//cout<<cnt;
		ll cnj=0;
		ll a=p[i].first;
		ll b=p[i].second;
		rep(j,1,m){
			ll c=q[j].first;
			ll d=q[j].second;
			ll cnt2=abs(a-c)+abs(b-d);
			//cout<<" "<<min(cnt,cnt2);
			//cout<<" "<<cnt2<<endl;
			if(cnt==cnt2) continue;
			//cout<<"apple";
			if(cnt>cnt2){
				cnt=cnt2;
				cnj=j;
				//cout<<"aho";
			}
		}
		ans[i]=cnj;
	}
	rep(i,0,n) cout<<ans[i]+1<<endl;
	return 0;
}