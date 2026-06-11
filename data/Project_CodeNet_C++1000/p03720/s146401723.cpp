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
int cnt[55];
signed main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
	}
	for(int i=1;i<=n;i++) cout<<cnt[i]<<"\n";
	re 0;
}