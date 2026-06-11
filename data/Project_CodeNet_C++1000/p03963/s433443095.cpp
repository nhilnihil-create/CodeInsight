#include<bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define acc_io cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define vvl vector<vector<ll>>
#define vl  vector<ll>
#define rep(i,sta,end) for(ll i=sta;i<end;i++)
//lcm:�ŏ����{���Agcd:�ő����
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back 
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  
//name[i]   -> vl  name(i)
//name[i][j]-> vvl name(i,vl(j))
//or-> ||
//map<int,int>mp

ll n;
ll k;
//string s;
signed main(){
	acc_io;
	ll ans;
	cin>>n>>k;
	ans=k;
	rep(i,0,n-1) ans*=(k-1);
	cout<<ans<<endl;
	return 0;
}
