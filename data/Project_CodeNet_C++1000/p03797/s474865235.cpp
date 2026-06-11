#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
ll n,m;  
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	if(n*2<=m) cout<<(n*2+m)/4;
	else cout<<m/2;
	re 0;
}