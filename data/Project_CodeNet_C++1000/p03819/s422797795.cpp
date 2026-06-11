#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#define FR first
#define SE second
#define lowbit(x) (x&-x)

using namespace std;

int sumv[100005];

void add(int x,int num) {
  for(;x;x-=lowbit(x)) sumv[x]+=num;
}

int sum(int x,int n) {
  int s=0;
  for(;x<=n;x+=lowbit(x)) s+=sumv[x];
  return s;
}

typedef pair<int,int> pr;

pr a[300005];

bool cmp(pr x,pr y) {
  return x.SE-x.FR>y.SE-y.FR;
}

int ans[100005];

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	a[i]=pr(x,y);
  	add(y,1);
  	add(x-1,-1);
  }
  sort(a+1,a+n+1,cmp);
  int l=1;
  for(int i=m;i>0;i--) {
  	while (l<=n&&a[l].SE-a[l].FR>=i) {
  		add(a[l].SE,-1);
  		add(a[l].FR-1,1);
  		l++;
	  }
	ans[i]=l-1;
    for(int j=i;j<=m;j+=i) ans[i]+=sum(j,m);
  }
  for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
  return 0;
}