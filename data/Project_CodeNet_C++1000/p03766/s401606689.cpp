#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return rand()%x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=1000005,mod=1000000007;
int n,sum[N],f[N];
ll ans;
int main(){
	n=read();
	sum[0]=f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=(sum[i-1]-(i>=2?f[i-2]:0)+mod)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}
	for(int i=0;i<n-1;i++){
		ans=(ans+(ll)f[i]*(n-1)%mod*(n-1))%mod;
		ans=(ans+(ll)f[i]*(i+1))%mod;
		//cout<<i<<" "<<ans<<endl;
	}
	ans=(ans+f[n]+(ll)f[n-1]*(n-1))%mod;
	cout<<ans<<endl;
}
/*
1 1 1
1 2 3
1 3 2
2 1 1
2 3 3
3 2 2
*/