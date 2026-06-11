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

const int mod=1e9+7;
int N,f[1000005];
inline void inc(int& x,int y){x=x+y<mod?x+y:x+y-mod;}

int main(){
	// freopen("in.in","r",stdin);
	N=read();
	f[0]=0,f[1]=N;
	REP(i,2,N){
		inc(f[i],(f[i-1]-f[i-2]+mod)%mod);
		inc(f[i],N-max(1,i-2));
		if(i>=3)inc(f[i],f[i-3]);
		inc(f[i],1ll*(N-1)*(N-1)%mod);
		inc(f[i],f[i-1]);
	}
	printf("%d\n",(f[N]-f[N-1]+mod)%mod);
	return 0;
}
