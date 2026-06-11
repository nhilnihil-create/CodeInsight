#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define gc getchar
#define pc putchar
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
#define rank __RANK
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
#define rd read
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int maxn=110;
int n,m,a[maxn],b[maxn];
int main(){
	int iodd=0;
	n=rd(),m=rd();
	Rep(i,1,m)a[i]=rd(),iodd+=a[i]&1;
	if(m==1){
		if(a[1]==1) puts("1 1\n1"); else{
			printf("%d 2\n%d %d\n",a[1],a[1]-1,1);
		}
		return 0;
	}
	if(iodd>2){
		puts("Impossible");
		return 0;
	} else{
		Rep(i,2,m){
			if(a[i]&1){
				if(a[1]&1) swap(a[m],a[i]); 
				else swap(a[1],a[i]);
			}
		}
		int t=0;
		if(a[1]>1) b[++t] = a[1] - 1;
		rep(i,2,m) b[++t] = a[i];
				   b[++t] = a[m] + 1;
		Rep(i,1,m){
			printf("%d ",a[i]);
		}puts("");
		writeln(t);
		Rep(i,1,t){
			printf("%d ",b[i]);
		}
	}
	return 0;
}