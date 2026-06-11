#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int a,b; cin >> a >> b;
  a &= 3;
  b %= 3;
  if(a == 0 || b == 0 || (a+b)%3 == 0){
    cout << "Possible";
  }
  else{
    cout << "Impossible";
  }
}