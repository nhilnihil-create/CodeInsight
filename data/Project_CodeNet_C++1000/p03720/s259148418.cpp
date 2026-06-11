#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, a, b;
  cin >> n >> m;
  vector<int> s(n);
  for(int i=0; i<m; ++i){
    cin >> a >> b;
    ++s[a-1];
    ++s[b-1];
  }
  for(int i=0; i<n; ++i) cout << s[i] << endl;
}

