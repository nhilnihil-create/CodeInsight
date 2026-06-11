#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#define FR first
#define SE second
#define lowbit(x) (x&-x)
#define inf 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef pair<int,ll> pr;

inline void add(pr &x,pr y) {
  x.FR+=y.FR;x.SE+=y.SE;
}

pr sumv[100005];

void add(int x,pr num) {
  for(;x;x-=lowbit(x)) add(sumv[x],num);
}

pr sum(int x,int n) {
  pr s(0,0);
  for(;x<=n;x+=lowbit(x)) add(s,sumv[x]);
  return s;
}

void add(int l,int r,pr num) {
  add(l-1,pr(-num.FR,-num.SE));
  add(r,num);
}

int num[100005];

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&num[i]);
  ll s=0;
  for(int i=1;i<n;i++)
    if (num[i]<num[i+1]) {
    	add(num[i]+1,num[i+1],pr(1,-num[i]-1));
    	s+=num[i+1]-num[i];
	}
	else {
		if (num[i]<m) add(num[i]+1,m,pr(1,-num[i]-1));
		add(1,num[i+1],pr(1,m-num[i]-1));
		s+=m-num[i]+num[i+1];
	}
  ll ans=inf;
  for(int i=1;i<=m;i++) {
  	pr t=sum(i,m);
  	ans=min(ans,s-(ll)t.FR*i-t.SE);
  }
  printf("%lld\n",ans);
  return 0;
}