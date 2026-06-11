#include<iostream>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int main(){
  int n;
  while(cin>>n){
    ll a=1;
    for(int i=2;i<=n;i++){
      a=(a*i)%mod;
    }
    cout<<a<<endl;
  }
  return 0;
}