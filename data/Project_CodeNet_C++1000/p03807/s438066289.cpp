#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,oc = 0,dc = 0,fo,fd;
  cin >> n;
  rep(i,n){
    int a;
    cin >> a;
    if(a%2 == 0) dc++;
    else oc++;
  }
  fo = oc%2;
  if(fo == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}