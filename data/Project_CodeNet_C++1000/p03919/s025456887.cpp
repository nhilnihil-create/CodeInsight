#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      string s; cin >> s;
      if(s == "snuke"){
      	cout << char('A'+j-1) << i << endl;
        return 0;
      }
    }
  }
  return 0;
}