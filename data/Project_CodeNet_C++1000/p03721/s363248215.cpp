#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vvl = vector<vector<ll>>;
using vl  = vector<ll>;
#define _GLIBCXX_DEBUG
#define acc_io cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;i++)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
const ll MOD = 1000000007;
const double PI = acos(-1);  
//name[i]   -> vl  name(i)
//name[i][j]-> vvl name(i,vl(j))
//or-> ||
//map<int,int>mp

ll n,k;
ll ans;
//string s;
signed main(){
	acc_io;
	cin>>n>>k;
	vector<pair<int,int>> ab(n);
	ll cnt=0;
	rep(i,0,n){
		cin>>ab[i].first>>ab[i].second;
	}
	sort(all(ab));
	rep(i,0,n){
		cnt+=ab[i].second;
		if(cnt>=k){
			ans=ab[i].first;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
