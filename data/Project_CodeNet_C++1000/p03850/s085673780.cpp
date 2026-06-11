#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a),_ed=(b);i<=_ed;++i)
#define DREP(i,a,b) for(int i=(a),_ed=(b);i>=_ed;--i)
#define mp(x,y) make_pair((x),(y))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
    return f?x:-x;
}

int n;
ll f[100005][3];
inline void chkmax(ll& x,ll y){x=x>y?x:y;}

int main(){
	// freopen("in.in","r",stdin);
	f[0][0]=0,f[0][1]=f[0][2]=-1e16;
	n=read();
	REP(i,1,n){
		int x=read();
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		f[i][1]=max(f[i-1][1],f[i-1][2]);
		f[i][2]=f[i-1][2];
		f[i][0]+=x,f[i][1]-=x,f[i][2]+=x;
		if(x<0)chkmax(f[i][2],f[i][1]),chkmax(f[i][1],f[i][0]);
	}
	printf("%lld\n",max(f[n][0],max(f[n][1],f[n][2])));
	return 0;
}
