#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int t[N],ans[N];
int main(){
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t[i],s+=t[i];
	int m;cin>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		ans[i]=s+y-t[x];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}