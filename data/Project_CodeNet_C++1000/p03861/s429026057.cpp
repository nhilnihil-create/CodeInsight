#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll a,b,x;
  cin >> a >> b >> x;
  
  if(a == b && b % x == 0){
    cout << 1 << endl;
  }else if(a == b){
    cout << 0 << endl;
    return 0;
  }else if(a == 0){
    cout << b / x + 1 << endl;
    return 0;
  }else{
    ll ansa = (a-1) / x + 1;
    ll ansb = b / x + 1; 
    cout << ansb - ansa << endl;
  }
  
}