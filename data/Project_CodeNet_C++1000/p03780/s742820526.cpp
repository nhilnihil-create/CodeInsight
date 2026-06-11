#include<cstdio>
#include<algorithm>
using namespace std;

int a[5000],dp[5011][5011];

int main(){
  int n,k,l,r,mid,flag;
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  sort(a,a+n);
  l=0;
  r=n-1;
  while(l<=r){
    for(int i=0;i<=n;i++)
      for(int j=0;j<=k;j++){
        if(j==0)
          dp[i][j]=1;
        else
          dp[i][j]=0;
      }
    mid=(r+l)/2;
    for(int i=0;i<n;i++){
      for(int j=0;j<=k;j++){
        if(dp[i][j]){
          dp[i+1][j]=1;
          if(i!=mid&&j+a[i]<=k)
            dp[i+1][j+a[i]]=1;
        }
      }
    }
    flag=0;
    for(int i=max(k-a[mid],0);i<k;i++)
      if(dp[n][i])
        flag=1;
    if(flag)
      r=mid-1;
    else
      l=mid+1;
  }
  printf("%d\n",r+1);
}