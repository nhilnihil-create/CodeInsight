//第一道黑题祭 
// Start 40 lines of header files acceleration
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
// End 40 lines of header files acceleration
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define re register
#define ll long long
#define N 2005
#define MAXN 4000000
using namespace std;
//

inline int read(){
    int x=0,f=1;
    char c;
    for(c=getchar();(!isdigit(c))&&(c!='-');c=getchar());
    if(c=='-') f=-1,c=getchar();
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
inline void print(int number){
    const int SIZE=25; int un=1,extent=0; char letter[SIZE];
    if(number<0){ number=-number; un=-1;}
    while(number){ letter[++extent]=number%10+'0'; number/=10;}
    if(!~un) putchar('-'); if(!extent) putchar('0');
    else while(extent) putchar(letter[extent--]);
}
inline int getint(){
    char ch = getchar(); int x = 0;
    while (ch < '0'|| ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
inline void putint(long long x){
	if (x > 9) putint(x / 10);
	putchar(x % 10 + '0');
}
//

const int Mod=1e9+7;
int n, k;
ll f[N][N], f1[MAXN+5], f2[MAXN+5];
//

inline ll Equation(int n,int m){
	return (((f1[m] * f2[n]) % Mod) * f2[m - n]) % Mod;
}
inline ll Answer(ll x,int P){
    ll ans = 1, m = x;
    while(P){
        if(P&1)
			(ans *= m) %= Mod;
        P >>= 1;
		(m*=m) %= Mod;
    }
    return ans;
}
//

int main(){
//    scanf("%d%d",&n,&k);
	n = read(), k = read();
	
    if(k==1)//特判 
	{
		printf("%d\n",1);
		return 0;
	}
	
    f1[0] = 1;
	for(re int i = 1; i <= MAXN; ++i)
		f1[i] = (f1[i-1] * i) % Mod;
		
    f2[MAXN] = Answer(f1[MAXN], Mod-2);
    
	for(re int i = MAXN - 1; i>=0; --i)
		f2[i] = (f2[i + 1] * (i + 1)) % Mod;
		
    f[0][0]=1;
    
    for(re int i = 1;i <= n; ++i){
        for(re int j = 0;j <= i; ++j){
            f[i][j] = f[i - 1][j];
            if(!j)
				continue;
            (f[i][j] += f[i][j - 1] * (n - j + 1) % Mod * Equation(k - 2,n - i + (n - j + 1) * (k - 1) - 1) % Mod) %= Mod;
        }
    }
//    printf("%lld\n",f[n][n]);
	print(f[n][n]);
    return 0;
}