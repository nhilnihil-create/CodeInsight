#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll x;
  cin >> x;

  ll a = x/11;
  ll b = x%11;

  if(b>=7){
    cout << a*2 + 2 << endl;
  }
  else if(b>=1){
    cout << a*2 + 1 << endl;
  }
  else{
    cout << a*2 << endl;
  }

  

  return 0;
}
