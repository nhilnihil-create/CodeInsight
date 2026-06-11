#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 1000005
#define mod 1000000007
using namespace std;
inline int in(){
    int x=0;bool f=0; char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
int f[MN],sum[(MN<<1)+5],n,res;
int main()
{
	n=in();f[n+1]=1;
	for (int i=(n<<1)+10;i>n;--i) sum[i]=(sum[i+1]+1)%mod;
	for (int i=n;i;--i){
		f[i]=(sum[i+3]+mod-sum[i+n+2])%mod;
		f[i]=(f[i]+f[i+1])%mod;
		if (i!=n) f[i]=(f[i]+(1ll*(n-1)*(n+mod-1)))%mod;
		sum[i]=(sum[i+1]+f[i])%mod; 
	}printf("%d",f[1]);return 0;
}