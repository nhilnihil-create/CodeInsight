#include<algorithm> // sort,reverse,min,lower_bound
#include<iostream>
using namespace std;
#define df 0
typedef long int li;
int judge(int j,int* a,int k,int n);

int main(){
  if(df) printf("*debug mode*\n");
  int n,k; cin >>n >>k;
  int a[n];
  li sum=0;
  for(int& x: a){
    cin>> x;
    sum+=x;
  }
  if (df)printf("sum:%d\n",sum);
  if(sum<k){
    printf("%d\n",n);
    return 0;
  }
  sort(a,a+n);
  if(df){
    printf("sort:");
    for(int x:a)printf("%d ",x);
    printf("\n");
  }
  int noneed=-1,need=n;
  while(need-noneed>1){
    int temp=(noneed+need)/2;
    if(df)printf("judge:%d\n",temp);
    int flag=judge(temp,a,k,n);
    if(df)printf("%d\n",flag);
    if(flag)need=temp;else noneed=temp;
  }
  printf("%d\n",need);
}

int judge(int j,int* a,int k,int n){
  int dp[k+1];
  dp[0]=1;for(int i=1;i<=k;i++)dp[i]=0;
  if(df){
    for(int x:dp)printf("%d",x);
    printf("\n");
  }
  for(int i=0;i<n;i++){
    if(i==j)continue;
    for(int t=k-a[i];t>=0;t--){
      dp[t+a[i]]|=dp[t];
    }
    if(df){
      for(int x:dp)printf("%d",x);
      printf("\n");

    }
  }
  for(int i=max(0,k-a[j]);i<k;i++){
    if(dp[i])return 1;
  }
  return 0;
}

/// confirm df==0 ///
