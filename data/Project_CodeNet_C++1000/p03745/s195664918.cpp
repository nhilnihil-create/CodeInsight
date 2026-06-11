#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  int p;
  cin >> p;
  int d = 0;
  int ans = 1;
  rep(i,n-1){
    int a;
    cin >> a;
    if(d == 1 && a < p){
      ans++;
      d = 0;
    }else if(d == -1 && a > p){
      ans++;
      d = 0;
    }else if(d == 0 && a < p){
      d = -1;
    }else if(d == 0 && a > p){
      d = 1;
    }
    p = a;
  }
  cout << ans << endl;
  return 0;
}
