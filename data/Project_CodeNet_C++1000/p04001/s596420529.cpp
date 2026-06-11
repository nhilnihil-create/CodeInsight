#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
   string S;
   cin >> S;

   ll ans = 0;
   const int len = S.size()-1;
   rep (i, 1<<len) {
      bitset<10> op(i);
      ll memo = 0;
      rep(j,len) {
         if(op.test(len-1-j)) {
            ans += (S.at(j)-'0') + memo;
            memo = 0;
         } 
         else memo = 10 * ((S.at(j)-'0') + memo);
      }
      ans += (S.at(len)-'0') + memo;
//      cout << "i : " << op << "    ans : " << ans << endl; 
   }
   cout << ans << endl;
   return 0;
}