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
const int maxn=5e2+5;
int n;
pa x[maxn];
int ans[maxn*maxn];
int main(){
	read(n);
	rep(i,1,n)read(x[i].w1),x[i].w2=i;
	sort(x+1,x+n+1);
	int pnt=0,cnt;
	rep(i,1,n){
		cnt=0;
		while((pnt+1)<x[i].w1&&cnt+1<x[i].w2){
			pnt++;
			if(!ans[pnt])ans[pnt]=x[i].w2,cnt++;
		}
		if(cnt!=x[i].w2-1)return puts("No"),0;
		ans[x[i].w1]=x[i].w2;
	}
	rep(i,1,n){
		cnt=0;
		while(cnt+1<=n-x[i].w2){
			pnt++;
			if(!ans[pnt]){
				ans[pnt]=x[i].w2,cnt++;
				if(pnt<x[i].w1)return puts("No"),0;
			}
		}
	}
	puts("Yes");
	rep(i,1,n*n)printf("%d ",ans[i]);
	return 0;
}