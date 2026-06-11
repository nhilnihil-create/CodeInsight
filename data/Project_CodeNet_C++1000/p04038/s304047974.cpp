#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const int MO=1e9+7;
int n,k;
LL f[2010][2010],ans,fac[4000010],inv[4000010];
LL pw(LL x,LL y){
	LL t=1;
	for (;y;y>>=1){
		if (y&1) t=t*x%MO;
		x=x*x%MO;
	}
	return t;
}
LL C(int x,int y){
	return fac[x]*inv[y]%MO*inv[x-y]%MO;
}
int main(){
	cin>>n>>k;
	if (k==1) return puts("1"),0;
	fac[0]=1;
	FOR(i,1,4000000) fac[i]=fac[i-1]*i%MO;
	inv[4000000]=pw(fac[4000000],MO-2);
	FORD(i,3999999,0) inv[i]=inv[i+1]*(i+1)%MO;
	f[0][0]=1;
	FOR(i,0,n) //>0
		FOR(j,0,i) //=0
			if (f[i][j]){
				if (j<i) (f[i][j+1]+=f[i][j])%=MO;
				if (i<n) (f[i+1][j]+=f[i][j]*(n-i)%MO*C(i*k-i+j+1+k-2-1,k-2))%=MO;
			}
	ans=(f[n][n]%MO+MO)%MO;
	cout<<ans<<endl;
	return 0;
}
