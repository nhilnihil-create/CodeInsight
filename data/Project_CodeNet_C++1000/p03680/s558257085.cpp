#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;



int main() {
  int n;
  int ans = 0;
  cin >> n;
  vector<int> button(n + 1, 0);
  vector<int> check(n + 1, -1);
  

  rep(i, n) cin >> button[i + 1]; 
  
  
  int next = 1;
  while(check[next] == -1 && next != 2)
  {
    check[next] = 0;
    next = button[next];
    ans ++;
  
  }
  if(next == 2) cout << ans << endl;
  else cout << -1 << endl;
  
    } 
   
  



