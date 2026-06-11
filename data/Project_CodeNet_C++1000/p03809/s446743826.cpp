#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
vi deg;
vi arr;
vector<vi> AdjList;
int n;
void dfs(int s, int p=-1) {
	int sum=0;
	int maxx=0;
	for(int u: AdjList[s]) {
		if(u==p) continue;
		if(u!=p) dfs(u,s);
		maxx=max(maxx,arr[u]);
		sum+=arr[u];
	}
	int able=min(sum/2,sum-maxx);
	if(deg[s]==1) return;
	if(arr[s]>sum) {
		cout<<"NO";
		exit(0);
	}
	if(sum-arr[s]>able&&deg[s]>1) {
		cout<<"NO";
		exit(0);
	}
	arr[s]=2*arr[s]-sum;
	if(arr[s]<0) {
		cout<<"NO";
		exit(0);
	}
} 
signed main() {
	cin>>n;
	deg.assign(n+1,0);
	arr.assign(n+1,0);
	AdjList.assign(n+1,vi());
	for(int i=1 ; i<=n ; i++) {
		cin>>arr[i];
	}
	if(n==2) {
		if(arr[1]!=arr[2]) {
			cout<<"NO";
			return 0;
		}
		else {
			cout<<"YES";
			return 0;
		}
	}
	for(int i=1 ; i<n ; i++) {
		int u,v;
		cin>>u>>v;
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
		deg[u]++; deg[v]++;
	}
	for(int i=1 ; i<=n ; i++) {
		if(deg[i]!=1) {
			dfs(i);
			if(arr[i]!=0) {
				cout<<"NO";
				return 0;
			}
			cout<<"YES";
			return 0;
		}
	}
}