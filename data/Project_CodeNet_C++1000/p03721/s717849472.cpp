#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll n,k,a[100010],b[100010],cnt[100010]={0};
  cin>>n>>k;
  rep(i,n)cin>>a[i]>>b[i];

  rep(i,n){
    cnt[a[i]]+=b[i];
  }


  ll tmp=0;
  rep(i,100010){
    tmp+=cnt[i];
    if(tmp>=k){
      cout<<i<<endl;
      return 0;
    }
  }

  return 0;
}
