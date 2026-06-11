#include<bits/stdc++.h>
using namespace std;
long long int n,a[10000001],x,y;
int main(){
  cin>>n;
  a[0]=0;
  for(int i=1;i<=n;i++){
    a[i]=a[i-1]+i;
    if(a[i]>=n){
      x=a[i]-n;
      y=i;
      break;
    }
  }
  for(int i=1;i<=y;i++){
    if(x!=i) cout<<i<<endl;
  }
  return(0);
}
