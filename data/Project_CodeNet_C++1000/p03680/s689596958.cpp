#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
/* start */

signed main(){
   IOS;
   int n; cin >> n;
   vector<int> next(n + 1), ok(n + 1);
   for(int i = 0; i < n; i++) {
      cin >> next[i + 1];
   }  
   int ans = 0, now = 1; // start
   while(++ans) {
      int cur = next[now]; 
      if(cur == 2) { // goal
         cout << ans << "\n";
         return 0;
      }
      if(!ok[cur]) ok[cur]++; 
      else {
         cout << "-1\n"; // loop
         return 0;
      }
      now = cur;
   }
}