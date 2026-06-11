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
int a[5005], n, k, sm;
bitset<5005>dp;
int solve(){
	cin>>n>>k; sm=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		a[i]=min(a[i], k);
		sm+=a[i];
	}
	sort(a+1, a+n+1);
	dp[0]=1;
	for(int i=n; i>=0; i--){
		bool rs=0;
		for(int j=k-1; j>=max(k-sm,0); j--){
			if(dp[j]){rs=1; break;}
		}
		if(!rs){
			cout<<i<<endl; return 0;
		}
		for(int j=k; j>=a[i]; j--) if(dp[j-a[i]]) dp[j]=1;;
		sm-=a[i];
	}
	return 0;
}