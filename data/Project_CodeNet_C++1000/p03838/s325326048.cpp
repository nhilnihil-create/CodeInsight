#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	int a,b; cin>>a>>b;
	int ans=0;
	if(a==b)ans=0;
	else if(b==0){
		if(a<0)ans=abs(a);
		else ans=a+1;
	}
	else if(abs(a)>abs(b)){
		if(a>=0 && b>=0)ans=a-b+2;
		else if(a<0 && b<0)ans=b-a;
		else if(a>=0 && b<0)ans=a+b+1;
		else ans=abs(a+b)+1;
	}
	else{
		if(a>=0 && b>=0)ans=b-a;
		else if(a<0 && b<0)ans=a-b+2;
		else if(a<0 && b>=a)ans=a+b+1;
		else ans=abs(a+b)+1;
	}
	cout<<ans<<endl;
	
	return 0;
}