#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,m; cin >> n >> m;

  vector<int> v(n, 0);

  int a = 0, b = 0;
  for(int i = 0; i < m; ++i) {
    cin >> a;
    v.at(a-1) += 1;
    cin >> b;
    v.at(b-1) += 1;
  }

  for(int x : v){
    cout << x <<"\n";
  }
}