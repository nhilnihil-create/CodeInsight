#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    ++v[a - 1];
    ++v[b - 1];
  }
  rep(i, n){
    cout << v[i] << endl;
  }
  return 0;
}