#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
unordered_map<int,int>mp;
int sz[2];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		mp[x]++;
	}
	for(auto p:mp){
		sz[p.se%2]++;
	}
	int ans=0;
	ans+=sz[1]+sz[0]/2*2; 
	cout<<ans;
	return 0;
}