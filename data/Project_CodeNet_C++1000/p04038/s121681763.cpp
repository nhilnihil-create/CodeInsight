#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

#define LL long long
#define DB double
#define MAXM 2000
#define MAXN 4000000
#define MOD 1000000007
#define Pr pair<int,int>
#define X first
#define Y second
#define INF 1000000000000000000
#define mem(x,v) memset(x,v,sizeof(x))

LL read(){
	LL x=0,F=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*F;
}

int add(int a,int b){return (a+b>=MOD)?a+b-MOD:a+b;}
int dec(int a,int b){return (a-b<0)?a-b+MOD:a-b;}
int mul(int a,int b){return (1LL*a*b)%MOD;}
int fst_pow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=mul(res,a);
		a=mul(a,a),b>>=1;
	}
	return res;
}

int n,k;
int fac[MAXN+5],ifac[MAXN+5];
int f[MAXM+5][MAXM+5];

void prepare(){
	fac[0]=1;
	for(int i=1;i<=MAXN;i++)fac[i]=mul(fac[i-1],i);
	ifac[MAXN]=fst_pow(fac[MAXN],MOD-2);
	for(int i=MAXN;i>=1;i--)ifac[i-1]=mul(ifac[i],i);
}
int Comb(int a,int b){
	return mul(fac[a],mul(ifac[b],ifac[a-b]));
}

int main(){
	n=read(),k=read();
	if(k==1){puts("1");return 0;}
	prepare();
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++){
			f[i][j]=f[i-1][j];
			if(j)f[i][j]=add(f[i][j],mul(mul(f[i][j-1],n-j+1),Comb(n*k-i-(k-1)*(j-1)-1,k-2)));
		}
	printf("%d",f[n][n]);
} 