#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pqgreater(x) x, vector<x>, greater<x>
#define abs(x) (x>0?x:-x)
#define decimal(x) cout<<fixed<<setprecision(x)
#define gc getchar//_unlocked
#define pc putchar//_unlocked
const ll mod=998244353;
int solve(); void precomp();

#define multitest 0
#define usecase 0
int main(){ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t=1;
	if(multitest) cin>>t;
	precomp();
	for(int tc=1; tc<=t; tc++){
		if(multitest && usecase)
			cout<<"Case #"<<tc<<": ";
		solve();
	}
}
void precomp(){	
	return;
}
int solve(){
	int w, a, b; cin>>w>>a>>b;
	if(max(a, b)<=min(a+w, b+w)) cout<<0<<endl;
	else if(a+w<b) cout<<b-a-w<<endl;
	else cout<<a-b-w<<endl;
	return 0;
}