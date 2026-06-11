#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000,INF=(1<<30)-1;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

LL mn[N+9];

LL Divide_ans(int l,int r){
  if (l==r) return a[l];
  int mid=l+r>>1;
  LL res=Divide_ans(l,mid)+Divide_ans(mid+1,r);
  mn[mid]=INF;mn[r+1]=0;
  for (int i=mid+1;i<=r;++i) mn[i]=min(mn[i-1],(LL)a[i]);
  for (int i=r;i>mid;--i) mn[i]+=mn[i+1];
  int now=a[mid];
  for (int i=mid,j=mid+1;i>=l;--i){
	now=min(now,a[i]);
	for (;j<=r&&now<=a[j];++j);
	res+=(LL)now*(j-mid-1)+mn[j];
  }
  return res;
}

void outo(){
  printf("%lld\n",Divide_ans(1,n));
}

int main(){
  into();
  outo();
  return 0;
}