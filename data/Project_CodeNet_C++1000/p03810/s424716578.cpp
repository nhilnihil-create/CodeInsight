#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define For(i,x,y) for(int i=(x);i<=(y);++i)
#define Rof(i,x,y) for(int i=(x);i>=(y);--i)
#define Edge(x) for(int i=head[x];i;i=e[i].nxt)
#define mset(x,y) memset(x,y,sizeof(x))
#define strL strlen
#define p_b push_back
#define mcpy(x,y) memcpy(x,y,sizeof(x))
#define lson l,mid,(o<<1)
#define rson mid+1,r,((o<<1)|1)
#define Ls (t[o].ls)
#define Rs (t[o].rs)
#define mod
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
int cnt[2],a[N];
int gcd(int x,int y){
	if(x<y) swap(x,y);
	return x%y?gcd(y,x%y):y;
}
int main(){
	int n;bool tk=1;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	while(1){
		cnt[1]=cnt[0]=0;
		ll sum=0;int _1=0,pos=0;
		For(i,1,n){
			if(a[i]==1) _1++;
			else{
				sum+=a[i]-1;
				if(a[i]%2) cnt[1]++,pos=i;
				else cnt[0]++;
			}
		}
		if(_1){
			if(sum%2==0) tk^=1;
			if(tk) puts("First");
			else puts("Second"); 
			return 0;
		} else{
			if(cnt[0]%2){
				if(tk) puts("First");
				else puts("Second");
				return 0;
			} else{
				if(cnt[1]>1){
					tk^=1;
					if(tk) puts("First");
					else puts("Second");
					return 0;
				} else{
					a[pos]--;int x=a[1];
					For(i,2,n) x=gcd(a[i],x);
					For(i,1,n) a[i]/=x;
					tk^=1;
				}
			}
		}
	}
}