#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cond(2, 0);
  rep(i, n) cin >> a[i];
  int cn = 0;
  rep(i,n-1){
    if (a[i] < a[i+1]){
      if(cond[1] == 1) {
        cn++;
        cond[0] = 0;
        cond[1] = 0;
        continue;
      }
      cond[0] = 1;
    }else if(a[i] > a[i+1]){
      if(cond[0] == 1){
        cn++;
        cond[0] = 0;
        cond[1] = 0;
        continue;
      }
      cond[1] = 1;
    }
  }
  cn++;
  cout << cn << endl;
}