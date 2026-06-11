#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if(abs(a-x) > abs(b-x)){
    cout << 'B';
  }
  else{
    cout << 'A';
  }
  return 0;
}


