#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll n,a,b;
  cin >>n >>a >>b;
  if(a>b){
    cout << 0 << endl;
    return 0;
  }
  if(n==1){
    if(a!=b) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
  }
  cout << (b-a)*(n-2)+1 << endl;
  return 0; 
}