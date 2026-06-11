#include<bits/stdc++.h>
#define loop(n,i) for(register int i=1;i<=(n);++i)
#define zxc(x) cerr<<(#x)<<'='<<(x)<<'\n'
#define zxcv(x) cerr<<(#x)<<'='<<(x)<<','
#define zcx zxc
#define MAX 5000009
#define int long long
#define P 1000000007
using namespace std;
typedef pair<int,int> pr;
inline int icin(){
	char c=getchar();int s=0;bool sign=0;
	while(!isdigit(c)&&c^'-')c=getchar();
	if(c=='-')c=getchar(),sign=1;
	while(isdigit(c))s=(s<<1)+(s<<3)+c-'0',c=getchar();
	return sign?-s:s;
}
int n,k;
inline int Quick(int a,int m){int ans=1;for(;m;m>>=1,a=a*a%P) if(m&1) ans=ans*a%P;return ans;}
int fact[MAX],ifact[MAX];
inline int binom(int n,int m){return n<m||m<0?0:fact[n]*ifact[m]%P*ifact[n-m]%P;}
int f[2009][2009];
main(){
	n=icin(),k=icin();
	if(k==1) return cout<<1,0;
	int bound=n*k+k;
	fact[0]=1;loop(bound,i) fact[i]=fact[i-1]*i%P;
	ifact[bound]=Quick(fact[bound],P-2);for(register int i=bound;i;--i) ifact[i-1]=ifact[i]*i%P;
	for(register int i=0;i<=n;++i) f[0][i]=1;
	for(register int i=1;i<=n;++i){
		for(register int j=i;j<=n;++j){
			f[i][j]=(f[i][j-1]+f[i-1][j]*binom((n-i+1)*(k-1)+n-j-1,k-2)%P*(n-i+1))%P;
		}
	}cout<<f[n][n];
}