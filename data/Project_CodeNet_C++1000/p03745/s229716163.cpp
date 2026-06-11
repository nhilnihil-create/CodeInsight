#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int cnt = 1;
  bool inc=true, dic=true;
  int m;
  cin >> m;
  rep(i,n-1) {
    int k;
    cin >> k;
    if(!inc&&k>m) {
      inc = true;
      dic = true;
      cnt++;
    }
    else if(!dic&&k<m) {
      inc = true;
      dic = true;
      cnt++;
    }
    else if(k>m) dic = false;
    else if(k<m) inc = false;
    m=k;
  }
  cout << cnt << endl;
}
