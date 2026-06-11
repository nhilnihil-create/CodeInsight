#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main(){
  long long int i,n,k,a[20],ans=1000000000000,sum=0,min=0;
  scanf("%lld %lld\n",&n,&k);
  for(i=0;i<n;i++){
    scanf("%lld\n",&a[i]);
  }
  for(int tmp=0;tmp<(1<<n);tmp++){
    int size=0;
    bitset<15> s(tmp);
    for(i=0;i<n;i++){
      if(s[i]==1){
        size++;
      }
    }
    if(size<k){
      continue;
    }
    for(i=0;i<n;i++){
      if(s[i]==1){
        if(a[i]>min){
          min=a[i];
        }
        else{
          sum=sum+(min-a[i]);
        }
        min++;
      }
      else{
        if(a[i]>min){
          min=a[i]+1;
        }
      }
    }
    if(sum<ans){
      ans=sum;
    }
    sum=0,min=0;
  }
  printf("%lld\n",ans);
  return 0;
}