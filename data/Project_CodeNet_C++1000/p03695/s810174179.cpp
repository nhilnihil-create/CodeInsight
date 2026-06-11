#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll n,a[110];
  cin>>n;
  rep(i,n)cin>>a[i];
  ll cnt[9]={0};
  rep(i,n){
    if(a[i]>=1&&a[i]<400){
      cnt[0]++;
    }else if(a[i]>=400&&a[i]<800){
      cnt[1]++;
    }else if(a[i]>=800&&a[i]<1200){
      cnt[2]++;
    }else if(a[i]>=1200&&a[i]<1600){
      cnt[3]++;
    }else if(a[i]>=1600&&a[i]<2000){
      cnt[4]++;
    }else if(a[i]>=2000&&a[i]<2400){
      cnt[5]++;
    }else if(a[i]>=2400&&a[i]<2800){
      cnt[6]++;
    }else if(a[i]>=2800&&a[i]<3200){
      cnt[7]++;
    }else if(a[i]>=3200){
      cnt[8]++;
    }
  }
  ll m=0;
  rep(i,8){
    if(cnt[i]>0)m++;
  }

  cout<<max(1LL,m)<<" "<<m+cnt[8]<<endl;
  return 0;
}
