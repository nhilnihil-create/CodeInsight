#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+50;
const int oo = 22;
int n, d, q;
int a[N];
map<int,int > M;
int P[N][oo];
signed main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	cin >> d;
	for(int i=1;i<=n;i++){
		int v = a[i] + d;
		int k = lower_bound(a+1,a+n+1,v) - a;
		if(a[k]>v||k==n+1)	k--;
		P[i][0] = k;
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			P[i][j] = P[P[i][j-1]][j-1];
		}
	}
	
	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		if(u>v) swap(u,v); 
		int lg = log2(n);
		int ans = 0;
		for(int i=lg;i>=0;i--){
			if(P[u][i]<v){
				u = P[u][i];
				ans+=(1<<i);
			}
		}
		cout << ans+1 << endl;
	}
}