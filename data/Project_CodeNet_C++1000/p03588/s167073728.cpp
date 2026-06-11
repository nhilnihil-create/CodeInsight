#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,a,b,amax=0,lb;
  
  cin >> n;
  for (i=0;i<n;i++){
    cin >> a >> b;
    if (amax<a){
      amax=a;
      lb=b;
    }
  }
  
  cout << amax+lb << endl;
  
  return 0;
}