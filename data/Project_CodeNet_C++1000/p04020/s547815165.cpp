#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  long long ans = 0;
  long long have = 0;
  for(int i = 0; i < n; i++){
    have += a.at(i);
    ans += have / 2;
    have %= 2;
    if(a.at(i) == 0) have = 0;
  }
  
  cout << ans << endl;
}