#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007ll;
int main()
{
  int n;
  scanf("%d",&n);
  static int x[100000];
  for(int i=0;i<n;i++){
    scanf("%d",x+i);
  }
  long long ans=1ll;
  int K=1;
  for(int i=1;i<n;i++){
    if(2*K==x[i]){
      ans*=K+1;
      ans%=mod;
    }
    else{
      K++;
    }
  }
  for(int t=1;t<=K;t++){
    ans*=t;
    ans%=mod;
  }
  printf("%lld\n",ans);
  return 0;
}
