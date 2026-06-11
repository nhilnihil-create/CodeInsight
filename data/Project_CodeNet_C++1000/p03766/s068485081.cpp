#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e6+11;
int n;
ll f[N],g[N];
int main(){
	cin>>n;f[1]=g[1]=n;
	rep(i,2,n){
		f[i]=f[i-1]+(i>=3?g[i-3]:0)+1ll*(n-1)*(n-1)+n-max(i-1,2)+1;
		g[i]=(g[i-1]+(f[i]%=MOD))%MOD; 
	}
	cout<<f[n]<<endl;
}