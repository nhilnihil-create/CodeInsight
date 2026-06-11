#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if((a == b && a == c) && a%2 == 0){
    cout << -1 << endl;
    return 0;
  }
  int cnt = 0;
  while(a%2 == 0 && b%2 == 0 && c%2 == 0){
    cnt++;
    int aa,bb,cc;
    aa = b/2+c/2;
    bb = a/2+c/2;
    cc = a/2+b/2;
    a = aa;b == bb;c = cc;
  }
  cout << cnt << endl;
}