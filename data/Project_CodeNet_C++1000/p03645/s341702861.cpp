#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, m;
  cin >> n >> m;
  vi vec(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    if (a == 1){
       vec.at(b)++;
    }
    if (b == n){
      vec.at(a)++;
    }
  }
  rep(i,n){
    if (vec.at(i) > 1){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
