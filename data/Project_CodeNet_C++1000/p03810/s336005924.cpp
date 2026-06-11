#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pa;
#define w1 first
#define w2 second
#define ls (x<<1)
#define rs (x<<1|1)
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define SZ(x) ((x).size())
#define All(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)])
template<class T>void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=1ll*x*x%p)if(k&1)res=1ll*res*x%p;return res;}
int getgcd(int x,int y){return !x?y:getgcd(y%x,x);}
const int maxn=1e5+5;
int n,ans;
int a[maxn];
void check(){
	int cnt=0;
	rep(i,1,n)cnt+=!(a[i]&1);
	if(!(cnt&1)){
		ans^=1;
		if(cnt+1==n){
			rep(i,1,n)if(a[i]&1){
				if(a[i]==1)return;
				a[i]--;
			}
			int d=0;
			rep(i,1,n)d=getgcd(d,a[i]);
			rep(i,1,n)a[i]/=d;
			check();
		}
	}
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	check();
	if(ans)puts("Second");
	else puts("First");
	return 0;
}