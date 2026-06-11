#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll N = 0, M = 0, X = 0;
  cin >> N >> M >> X;
  rep(i,10000){
    ll tmp = 0;
    tmp = N*(i+1) % M;
    if(tmp == X){
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}