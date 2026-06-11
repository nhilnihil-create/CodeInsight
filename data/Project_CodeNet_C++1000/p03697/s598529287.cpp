#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int x,a,b; cin >>x>>a>>b;
  if(x + a > 9){
    cout << "error";
  }
  else{
    cout << x+a;
  }
}