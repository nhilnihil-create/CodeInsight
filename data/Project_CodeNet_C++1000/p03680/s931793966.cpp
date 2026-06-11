#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll n,a[100010];
  cin>>n;
  rep(i,n)cin>>a[i];
  ll num=0;
  ll tmp=0;
  ll ans=1;
  if(a[0]==2){
    cout<<1<<endl;
    return 0;
  }
  while(1){
    ans++;
    num=a[num]-1;
    tmp=a[num];
    if(tmp==2){
      cout<<ans<<endl;
      return 0;
    }
    if(ans>=n){
      cout<<-1<<endl;
      return 0;
    }
  }

  return 0;
}
