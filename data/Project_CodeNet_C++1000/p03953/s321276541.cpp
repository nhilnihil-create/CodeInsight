#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
int num[100005],s[100005];
int id[100005],now[100005];
bool vis[100005];
int ans[100005];
 
int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
    scanf("%d",&num[i]);
    if (i>1) s[i-1]=num[i]-num[i-1];
  }
  for(int i=1;i<n;i++) id[i]=i;
  int m;
  ll k=0;
  scanf("%d%lld",&m,&k);
  for(int i=1;i<=m;i++) {
    int x;
    scanf("%d",&x);
    swap(id[x-1],id[x]);
  }
  for(int i=1;i<n;i++)
    if (!vis[i]) {
      int x=i,cnt=0;
      while (!vis[x]) {
        now[cnt++]=x;
        vis[x]=1;
        x=id[x];
      }
      for(int i=0;i<cnt;i++)
        ans[now[i]]=now[(i+k)%cnt];
    }
  ll sum=num[1];
  for(int i=1;i<=n;i++) {
    printf("%lld.0\n",sum);
    sum+=s[ans[i]];
  }
  return 0;
}
