#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n,a[N];
LL l[N],r[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=3*n;i++)cin>>a[i];
  //
  priority_queue<int>q;
  LL tot=0;
  for(int i=1;i<=n;i++){
    tot+=a[i];
    q.push(-a[i]);
  }
  l[n]=tot;
  for(int i=n+1;i<=2*n;i++){
    //[1,i]  [i+1,3n]
    q.push(-a[i]);
    tot+=a[i];
    tot+=q.top();
    q.pop();
    l[i]=tot;
  }
  while(!q.empty())q.pop();tot=0;
  for(int i=3*n;i>2*n;i--)tot+=a[i],q.push(a[i]);
  r[2*n+1]=tot;
  for(int i=2*n;i>n;i--){
    tot+=a[i];
    q.push(a[i]);
    tot-=q.top();
    q.pop();
    r[i]=tot;
  }
  LL ans=LLONG_MIN;
  for(int i=n;i<=2*n;i++){
    ans=max(ans,l[i]-r[i+1]);
  }
  cout<<ans<<'\n';
  return 0;
}