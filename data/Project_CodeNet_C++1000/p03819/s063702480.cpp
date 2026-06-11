#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}


#define pii pair<int,int>
#define l first
#define r second

const int N=3e5+5;
int n,m,tr[N];
pii a[N];

inline bool cmp(const pii &x,const pii &y){
	return x.r-x.l<y.r-y.l;
}

#define lowbit(x) (x&(-x))

void up(int x,int v){
	while(x<=n){
		tr[x]+=v;
		x+=lowbit(x); 
	}
}

int que(int x){
	int res=0;
	while(x){
		res+=tr[x];
		x-=lowbit(x);
	}
	return res;
}

signed main(){
	read(m);read(n);
	for(int i=1;i<=m;i++) read(a[i].l),read(a[i].r);
	sort(a+1,a+1+m,cmp);
	for(int i=1,pt=1;i<=n;i++){
		int cur=0;
		while(pt<=m&&a[pt].r-a[pt].l+1<i) up(a[pt].l,1),up(a[pt].r+1,-1),pt++;
		for(int j=i;j<=n;j+=i) cur+=que(j);
		write(cur+m-pt+1);puts("");
	}
}