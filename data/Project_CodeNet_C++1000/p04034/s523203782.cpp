#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+5;
int a[N];
int b[N];
void solve(){
	int n,m; 
	cin>>n>>m; 
	for(int i=1;i<=n;i++)b[i]=1;
	a[1] = 1;
	for(int i=0;i<m;i++){
		int x,y; 
		cin>>x>>y; 
		if(a[x])a[y] = 1;
		b[x]--;
		b[y]++;
		if(b[x]==0)a[x] = 0;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(a[i])ans++;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
