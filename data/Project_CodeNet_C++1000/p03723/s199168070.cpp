#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll A = 0,B = 0,C = 0,a = 0,b = 0,c = 0;
  cin >> A >> B >> C;
  rep(i,1000){
    if(A % 2 != 0 || B % 2 != 0 || C % 2 != 0){
      cout << i;
      return 0;
    }
    a = (B + C)/2;
    b = (A + C)/2;
    c = (A + B)/2;
    A = a; B = b; C = c;
  }
  cout << "-1";
}