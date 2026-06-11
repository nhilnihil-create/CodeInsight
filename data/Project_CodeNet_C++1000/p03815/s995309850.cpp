#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
  ll n,y;
  cin>>n;
  y = n % 11;
  if(y > 0 && y < 7){
    cout<<(n / 11) * 2 + 1 <<"\n";
  }else if(y == 0){
    cout<<n / 11 * 2 <<"\n";
  }else{
    cout<<(n / 11) * 2 + 2<<"\n";
  }
  return 0;
}