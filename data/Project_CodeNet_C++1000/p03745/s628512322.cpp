#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,ans = 1;scanf("%d",&n);
  int a[n];short g = 2;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<n;i++){
    if(g == 2 && a[i] != a[i-1]){
      g = a[i]>a[i-1];
    }
    else if(g == 1 && a[i]<a[i-1]){
      ans++;g = 2;
    }
    else if(g == 0 && a[i]>a[i-1]){
      ans++;g = 2;
    }
  }
  printf("%d\n",ans);
}