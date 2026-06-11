#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  
  int64_t sum = 0;  
  
  for (int tmp = 0; tmp < (1 << ((int)S.size() - 1)); tmp++) {
    bitset<9> s(tmp);
    string T;
    
    for (int i = 0; i < ((int)S.size() - 1); i++) {
      T += S.at(i);
      if (s.test(i)) T += "+";
    }
    T += S.at(S.size() - 1);

    string num;     
    
    for (int i = 0; i < T.size(); i++) {
      if (T.at(i) == '+') {
        sum += stol(num);
        num = "";
      } else {
        num += T.at(i);
      }
    }
    sum += stol(num);
  }
  cout << sum << endl;
}