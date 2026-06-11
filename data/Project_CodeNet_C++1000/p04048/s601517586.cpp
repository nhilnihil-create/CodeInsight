#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll n,ll m){
  if(m==0){
    return n;
  }
  else{
    return gcd(m,n%m);
  }
}

int main(){
  ll n,x;
  cin >> n >> x;
  cout << 3*(n-gcd(n,x)) << endl;
}