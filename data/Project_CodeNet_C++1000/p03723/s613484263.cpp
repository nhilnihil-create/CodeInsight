#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	ll a,b,c; cin>>a>>b>>c;
	if(a%2==1 && b%2==1 && c%2==1){
		cout<<0;
		return 0;
	}
	else if(a==b && b==c){
		cout<<"-1";
		return 0;
	}
	set<vl> s;
	ll ans=0;
	while(a%2==0 && b%2==0 && c%2==0){
		ll n=a/2,m=b/2,k=c/2;
		a=m+k;
		b=n+k;
		c=m+n;
		vl vec(3);
		vec[0]=a;
		vec[1]=b;
		vec[2]=c;
		/*if(s.count(vec)){
			cout<<-1;
			return 0;
		}*/
		s.insert(vec);
		++ans;
	}
	cout<<ans;
	
	
	
	return 0;
}