#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
   string S;
   cin >> S;
   
   int length = S.size()-1;
   int len = 0;
   long long ans = 0;
   long long term = 0;
//   cout << length << endl;

   rep(i, (1<<length)){
      bitset<10> pluss(i);
      rep(j,length){
         if(pluss.test(j)) {
            term = stoll(S.substr(j-len,len+1));
            ans += term;
//            cout << term << endl;
            len = 0;
         }
         else len++;
//         cout << "len : " << len << endl;
      }
      term = stoll(S.substr(length-len,len+1));
      ans += term;
//      cout << term << endl << endl;
      len = 0;
   }

   cout << ans << endl;
   return 0;
}