#include<queue>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
int main(){
  const int mod=1000000007;
  int k,j,i,n,a[1010];
  long long ans=1;
  scanf("%d\n",&n);
  if(n==1){
    printf("1\n");
    return 0;
  }
  for(i=1;i<=n;i++){
    a[i]=0;
  }
  for(i=2;i<=n;i++){
    k=i;
    for(j=2;j*j<=i;j++){
      if(k%j==0){
        while(k%j==0){
          a[j]++;
          k=k/j;
        }
      }
    }
    if(k!=1){
      a[k]++;
    }
  }
  for(i=2;i<=n;i++){
    ans=ans*(a[i]+1)%mod;
  }
  printf("%lld\n",ans);
  return 0;
}