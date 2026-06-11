#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int N;
  cin >> N;
  if(N<2) cout << 1;
  else if(N<4) cout << 2;
  else if(N<8) cout << 4;
  else if(N<16) cout << 8;
  else if(N<32) cout << 16;
  else if(N<64) cout << 32;
  else cout << 64;



}