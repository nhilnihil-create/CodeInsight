#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
  int n,m; cin >>n >>m;
  vector<int> x(n, 0);
  rep(i,m){
    int a,b; cin >>a >>b;
    if(a==1) x[b]++;
    if(b==n) x[a]++;
  }
  for(int i = 2; i<n; i++){
    if(x[i]==2){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}