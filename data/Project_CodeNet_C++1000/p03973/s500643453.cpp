#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n+1]={};
  for(int i=0;i<n;i++) cin>>a[i];

  ll ans=0;
  int ma=0;
  for(int i=0;i<n;i++){
      if(ma+1==a[i]) ma=a[i];
      else{
          ll z=(a[i]-1)/(ma+1);
          ans+=z;
      }
      if(ma==0) ma=1;
  }

  cout<<ans<<endl;

  return 0;
}
