#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
int main(){
  ll n,x;cin >> n >> x;
  if(n==x*2){
    cout << x*3 << endl;
  }
  else{
    cout << (n-gcd(n,x))*3 << endl;
  }
}