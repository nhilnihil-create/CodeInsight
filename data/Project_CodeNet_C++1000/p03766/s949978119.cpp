#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
const int maxn=1000010;
const ll mod=1e9+7;
int n;
ll pre=1,tmp,f[maxn];
int main() {
	read(n);
	tmp=1LL*n*(n-1)%mod;
	f[1]=n;
	f[2]=1LL*n*n%mod;
	for(int i=3;i<=n;i++) {
		f[i]=(f[i-1]+pre+tmp-(i-2))%mod;
		(pre+=f[i-2])%=mod;
	}
	writeln(f[n]%mod);
	return 0;
}