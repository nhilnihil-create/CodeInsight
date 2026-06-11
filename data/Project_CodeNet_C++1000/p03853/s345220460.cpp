#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vvl = vector<vector<ll>>;
using vl  = vector<ll>;
#define _GLIBCXX_DEBUG
#define acc_io cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define DBG(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
const ll MOD = 1000000007;
const double PI = acos(-1);  
//name[i]   -> vl  name(i)
//name[i][j]-> vvl name(i,vl(j))
//or-> ||
//map<int,int>mp

signed main(){
	acc_io;
	int h,w;
	cin>>h>>w;
	vector<string>s(h);
	rep(i,0,h) cin>>s[i];
	rep(i,0,h){
		cout<<s[i]<<endl;
		cout<<s[i]<<endl;
	}
	return 0;
}
