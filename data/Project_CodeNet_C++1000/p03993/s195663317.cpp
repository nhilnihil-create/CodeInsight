#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,i,m=0;
  cin>>n;
  long long a[n+1];
  for(i=1;i<=n;i++)
  cin>>a[i];
  for(i=1;i<=n;i++){
      if(i==a[a[i]])
      m++;
  }m=m/2;
  cout<<m;

  return 0;
  
}
