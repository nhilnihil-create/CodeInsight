#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int a[N],vis[N];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int  x=1,s=0;
	while(x!=2&&!vis[x]){
		vis[x]=1,x=a[x];
		s++; 
	}
	printf(x!=2?"-1":"%d\n",s); 
	return 0;
}