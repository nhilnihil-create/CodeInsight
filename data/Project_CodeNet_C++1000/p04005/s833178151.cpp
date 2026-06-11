#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  ll a,b,c,result;
  cin >> a >> b >> c;
  if(a%2 == 0 || b%2 == 0 || c%2 == 0) 
    result = 0;
  else{
    result = min(b*c,a*c);
    result = min(result,a*b);
  }
  cout <<result;
}
