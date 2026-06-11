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

const int N=2e5+5;
int n,m,ans,a[N];
bool b[N];

bool check(int x){
	for(int i=1;i<=n;i++) b[i]=a[i]<=x;
	int flag=-1,mi=n;
	for(int i=2;i<=n;i++) if(b[i]==b[i-1]) if(abs(m-i)<mi){
		mi=abs(m-i);
		flag=b[i];
	}
	for(int i=n-1;i>=1;i--) if(b[i]==b[i+1]) if(abs(m-i)<mi){
		mi=abs(m-i);
		flag=b[i];
	}
	if(flag==-1) flag=b[1];
	return flag;
}

signed main(){
	m=read(n);n=n*2-1;
	for(int i=1;i<=n;i++) read(a[i]);
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	write(ans);
}