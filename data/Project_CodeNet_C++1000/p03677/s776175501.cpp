#include <bits/stdc++.h>
#define ll long long
#define Max(a,b) (a>b?a:b)
const int N=100050;
using namespace std;
inline int gi(){
  char ch=getchar();int x=0,q=0;
  while(ch<'0' || ch>'9') ch=='-'?q=1:0,ch=getchar();
  while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return q?(-x):x;
}
int a[N];
ll t[N],sum,ans;
int main(){
  int n=gi(),m=gi();
  for (int i=1; i<=n; ++i){
    a[i]=gi();
    if (a[i]>a[i-1]) sum+=a[i]-a[i-1];
    else sum+=m+a[i]-a[i-1];
  }
  sum-=a[1];
  for (int i=2; i<=n; ++i)
    if (a[i]>a[i-1]){
      if (a[i]>a[i-1]+1)
	++t[a[i-1]+2],t[a[i]+1]-=a[i]-a[i-1],t[a[i]+2]+=a[i]-a[i-1]-1;
    }
    else{
      if (a[i-1]==m&&a[i]==1) continue;
      ++t[a[i-1]+2];
      if (a[i-1]==m) ++t[2];
      else t[1]+=m-a[i-1],t[2]-=m-a[i-1]-1;
      t[a[i]+1]-=m-a[i-1]+a[i],t[a[i]+2]+=m-a[i-1]+a[i]-1;
    }
  for (int i=1; i<=m; ++i) t[i]+=t[i-1];
  for (int i=1; i<=m; ++i)
    t[i]+=t[i-1],ans=Max(ans,t[i]);
  cout<<sum-ans;
  return 0;
}
