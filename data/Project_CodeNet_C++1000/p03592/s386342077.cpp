#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  rep(a,0,m+1){
    rep(b,0,n+1){
      if(a*n+b*(m-2*a) == k){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}