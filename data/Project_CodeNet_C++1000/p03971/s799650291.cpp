#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define int ll
#define MOD (ll)(1e9+7)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,a,b; cin>>n>>a>>b;
	a+=b;
	string s; cin>>s;
	for(auto &i:s){
		bool ac=false;
		if(i=='a' && a>0){
			ac=true;
			a--;
		}
		else if(i=='b' && a>0 && b>0){
			ac=true;
			a--; b--;
		}
		if(ac) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}










