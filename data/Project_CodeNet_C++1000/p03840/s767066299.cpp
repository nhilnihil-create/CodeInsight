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
  ll I,O,T,J,L,S,Z;
  cin>>I>>O>>T>>J>>L>>S>>Z;

  ll ans=O;
  if((I%2+J%2+L%2)>=2){
    if(I>0&&J>0&&L>0){
      ans=ans+3;
      I--;
      J--;
      L--;
    }
  }
  ans=ans+(I/2)*2;
  ans=ans+(L/2)*2;
  ans=ans+(J/2)*2;
  cout<<ans<<endl;

  return 0;
}
