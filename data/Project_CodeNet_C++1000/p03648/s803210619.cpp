#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  ll k;
  cin>>k;
  ll n=50;
  cout<<n<<endl;
  ll a[n+1]={};
  if(k<n){
    for(int i=0;i<k;i++){
      cout<<n<<" ";
    }
    for(int i=k;i<n-1;i++){
      cout<<0<<" ";
    }
    cout<<0<<endl;
    return 0;
  }


  for(int i=0;i<n;i++){
    a[i]=n-1+(k/n);
  }

  for(int i=0;i<k%n;i++){
    a[i]+=n-k%n+1;
  }

  for(int i=k%n;i<n;i++){
    a[i]-=k%n;
  }


  for(int i=0;i<n-1;i++){
    cout<<a[i]<<" ";
  }
  cout<<a[n-1]<<endl;

  return 0;
}
