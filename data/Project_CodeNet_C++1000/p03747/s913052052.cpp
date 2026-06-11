#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define pc putchar
#define gc getchar
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void wri(ll x){write(x),pc(' ');}
void writeln(ll x){write(x);pc('\n');}
int a[100035],n,l,t,x,cnt;
int main(){
	n = read(),l = read(),t = read();
	Rep(i,1,n){
		a[i] = read();x = read();
		a[i] += x==1 ? t : -t;
		cnt += a[i] / l;
		if(a[i] % l < 0) cnt--;
		((a[i]%=l)+=l)%=l;
	}sort(a+1,a+1+n);
	((cnt%=n)+=n)%=n;
	Rep(i,cnt+1,n) writeln(a[i]);
	Rep(i,1,cnt) writeln(a[i]);
	return 0;
}