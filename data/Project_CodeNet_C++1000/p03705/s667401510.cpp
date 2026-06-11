#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll n,a,b; cin >>n >>a >>b;
  if(a>b){
    cout << 0 << endl;
    return 0;
  }
  if(n==1){
    if(a!=b) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
  }
  ll m = (n-1)*a+b;
  ll M = a+(n-1)*b;
  cout << M-m+1 << endl;
  return 0; 
}