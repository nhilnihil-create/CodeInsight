#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  string s,t; cin >> s >> t;
  int cnt = 0;
  if(n == 1){
    if(s.at(0) == t.at(0))
      cout << 1;
    else
      cout << 2;
    return 0;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i; j++){
      if(s.at(i+j) == t.at(j)) cnt++;
     // cout << i << "  " << j << "  " <<s.at(j) << "  " << t.at(j) << "  " << cnt << endl;
    }
    if(cnt == n - i){
      cout << n + i;
      return 0;
    }
    cnt = 0;
  }
  cout << 2 * n;
}