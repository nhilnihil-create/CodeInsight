#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int64_t ans = 0, N = S.size();
  for (int s = 0; s < (1 << (N - 1)); s++){
    bitset<12> d(s);
    int64_t A = 0, tmp = S.at(0)-'0';
    for (int i = 0; i < N - 1; i++){
      if (d.test(i)){
        tmp = (tmp * 10) + S.at(i + 1)-'0';
      }
      else{
        A += tmp;
        tmp =S.at(i + 1)-'0';
      }
    }
    ans += (A + tmp);
  }
  cout << ans << endl;

}