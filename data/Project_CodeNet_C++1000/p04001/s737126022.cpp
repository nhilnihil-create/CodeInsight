#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int len = S.length();
  int nbits = len -1;
  int64_t ans = 0;
  
  for (int tmp = 0; tmp < (1 << nbits); tmp++) {
  bitset<11>  s(tmp);
  // (ビット列sに対する処理)
    string tasareru, tasu;
    int previous_cut = -1;
    for(int i =0; i < nbits; i++){
      if ( s.test(i)){
        tasareru = S.substr(1 + previous_cut, i - previous_cut);
   //     cout << tasareru << ", ";
        previous_cut = i;
        ans += stoll(tasareru);
      }
    }
      //  cout << S.substr(1+previous_cut) << endl;
        ans += stoll(S.substr(1+previous_cut));
  }
  cout << ans << endl;
}
