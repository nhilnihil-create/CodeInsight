#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,k,x,y,a,ans=0;
  cin>>n>>k>>x>>y;
  a=x;
  for(int i=0;i<n;i++){
    if(i==k){
      a=y;
    }
    ans+=a;
  }
  cout<<ans<<"\n";
  
  return 0;
}