#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define int long long
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
const int BufferSize=1<<16;
char buffer[BufferSize],*head,*tail;

inline char Getchar() {
    if(head==tail) {
        int l=fread(buffer,1,BufferSize,stdin);
        tail=(head=buffer)+l;
    }
    return *head++;
}
inline int exread() {
    int x=0,f=1;char c=Getchar();
    for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
    return x*f;
}

inline int read(){
	int sum=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return f*sum;
}


const int N=200005;
struct node{int pre,nxt,to2,sp2,to1,sp1;}a[N];
struct ques{int l,r,ans;}q[N];
int n,m,L,p[N];
int bl[N],gap;

inline int work2(int l,int r){
	int ans=0;
	while(bl[l]!=bl[r]&&bl[l]!=bl[n]&&l<r){
		ans+=a[l].sp2,l=a[l].to2;
		ans++;l=a[l].nxt;
	}
	while(l<r) ans++,l=a[l].nxt;
	return ans;
}

inline int work1(int l,int r){
	int ans=0;
	while(bl[l]!=bl[r]&&bl[l]!=bl[1]&&l>r){
		ans+=a[l].sp1,l=a[l].to1;
		ans++;l=a[l].pre;
	}
	while(l>r) {ans++,l=a[l].pre;}
	return ans;
}

signed main(){
//	freopen("test.in","r",stdin);
//	freopen("B.out","w",stdout);
	n=read();gap=sqrt(n);
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) bl[i]=(i-1)/gap+1;
	L=read();m=read();
	for(int i=1;i<=m;i++) q[i].l=read(),q[i].r=read();
	for(int i=1;i<=n;i++){
		int k=p[i]+L;
		k=upper_bound(p+1,p+n+1,k)-p-1;
		a[i].nxt=k;
		a[i].pre=lower_bound(p+1,p+n+1,p[i]-L)-p;
	}
	for(int i=1;i<=n;i++){
		int p=i;
		while(bl[a[p].nxt]==bl[i]&&bl[p]!=bl[n]) p=a[p].nxt,a[i].sp2++;
		a[i].to2=p;
		p=i;
		while(bl[a[p].pre]==bl[i]&&bl[p]!=bl[1]) p=a[p].pre,a[i].sp1++;
		a[i].to1=p;
	}
	for(int i=1;i<=m;i++){
		if(q[i].l<q[i].r) q[i].ans=work2(q[i].l,q[i].r);
		else q[i].ans=work1(q[i].l,q[i].r);
	}
	for(int i=1;i<=m;i++) printf("%lld\n",q[i].ans);
	return 0;
}
