#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define N 10

int main() {
  string S;
  long long sum = 0;
  long long res = 0;

  cin >> S;
  
  rep(tmp,1 << S.size()-1){
    bitset<N> index(tmp);

    long long sum = 0;
    rep(i,S.size()){
      sum = 10*sum + (S.at(i)-'0');

      if(S.size()-2-i >= 0){
        if(index.test(i)){
          res += sum;
          sum = 0;
        }
      }
    }
    res += sum;
  }

  cout << res << endl;
  
  return 0;
}