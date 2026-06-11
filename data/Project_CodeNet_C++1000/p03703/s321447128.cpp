#include <bits/stdc++.h>
#define ll long long
#define lb(x) (x & -x)
#define N (200005)
 
using namespace std;
 
int sum[N],k,n,tot;
ll hsh[N],a[N],ans;

inline int gi(){
	int x=0,q=1; char ch=getchar();
	while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
  	if (ch=='-') q=-1,ch=getchar();
  	while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar();
  	return q*x;
}

void add(int x){
	for (;x<=tot;x+=lb(x)) sum[x]++;
}

int query(int x){
	int res=0;
	for (;x;x-=lb(x)) res+=sum[x];
	return res;
}

int main(){
  	n=gi(),k=gi();
  	for (int i=1;i<=n;++i) a[i]=a[i-1]+gi();
  	for (int i=1;i<=n;++i) a[i]-=1LL*k*i,hsh[i]=a[i];
  	hsh[tot=n+1]=0,sort(hsh+1,hsh+tot+1);
	tot=unique(hsh+1,hsh+tot+1)-hsh-1;
  	for (int i=0;i<=n;++i){
  		a[i]=lower_bound(hsh+1,hsh+tot+1,a[i])-hsh;
  		ans+=query(a[i]),add(a[i]);
	}
	cout<<ans; return 0;
}