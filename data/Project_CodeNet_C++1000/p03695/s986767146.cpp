#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  set<int> cnt;
  int free = 0;
  for(auto now : a){
    if(now > 3199){
      free++;
      continue;
    }
    
    int div = now / 400;
    cnt.insert(div);
  }
  
  int ans = cnt.size();
  if(ans == 0){
    ans = 1, free--;
  }
  cout << ans << " " << ans+free << endl;
}