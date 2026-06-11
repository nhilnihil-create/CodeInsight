#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,j,k)  for(register int i=(int)(j);i<=(int)(k);i++)
#define rrep(i,j,k) for(register int i=(int)(j);i>=(int)(k);i--)

ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

const int mod=1e9+7;
const int maxn=3050;
int n,k;
ll f[maxn][maxn];
ll fac[maxn*maxn],inv[maxn*maxn];

inline int C(int x,int y){
	if(x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int main(){
	n=read(),k=read();
	if(k==1){
		puts("1");
		return 0;
	}
	fac[0]=1;
	rep(i,1,3000*3000) fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	rep(i,2,3000*3000) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	rep(i,1,3000*3000) inv[i]=inv[i]*inv[i-1]%mod;
	f[0][0]=1;
	rep(i,1,n){
		rrep(j,i,0){
			f[i][j]=f[i][j+1]%mod;
			if(j){
				f[i][j]+=f[i-1][j-1]*C(i*k-j-1,k-2)%mod;
				f[i][j]%=mod;
			}
		}
	}
	cout<<f[n][0]*fac[n]%mod;
	return 0;
}
