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
  ll k;
  cin>>k;
  ll n=50;
  ll a[n+1]={};
  cout<<n<<endl;
  if(k<=n){
    for(int i=1;i<=k;i++){
      cout<<n<<" ";
    }
    for(int i=k+1;i<=n;i++){
      cout<<0<<" ";
    }
    cout<<endl;
    return 0;
  }

  for(int i=1;i<=k%n;i++){
    a[i]=2*50+(k-n)/n-k%n+1;
  }
  for(int i=k%n+1;i<=n;i++){
    a[i]=50+(k-n)/n-k%n;
  }

  for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;

  return 0;
}
