#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll n,m; cin >> n >> m;
  if(n == 1){
    n += 13;
  }
  if(m == 1){
    m += 13;
  }
  if(n>m){
    cout << "Alice";
  }
  else if(n<m){
    cout << "Bob";
  }
  else{
    cout << "Draw";
  }
}