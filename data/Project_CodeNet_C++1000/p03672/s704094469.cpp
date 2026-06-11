#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define int ll
#define MOD (ll)(1e9+7)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

inline bool check(const string &s,int n){
	For(i,0,n/2-1) if(s[i]!=s[i+n/2]) return false;
	return true;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s; cin>>s;
	for(int i=s.size()-2;i>0;i-=2){
		if(check(s,i)){
			cout<<i<<"\n";
			return 0;
		}
	}
}










