#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  const int64_t num = S.size();

  int64_t ans = 0;
  int64_t count = (int)pow(2, num-1);

  for (int64_t tmp = 0; tmp < (1 << 10); tmp++) {
    if(count == tmp)
      break;
    bitset<10> b(tmp);

    int64_t sum = 0;
    string T = "";
    for (int64_t i = 0; i < num; i++) {

      if(b.test(0)){
        T += S.at(i);
	    sum += stol(T);
        T = "";
      }else{
      	T += S.at(i);
      }

      b = b >> 1;
    }
    if(T.size() > 0)
	  sum += stol(T);
    ans += sum;
  }

  cout << ans << endl;

}
