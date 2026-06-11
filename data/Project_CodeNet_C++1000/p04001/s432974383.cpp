#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
    string S;
    cin >> S;
    ll out = 0;
    ll N = S.size();

    for (int bit = 0; bit < (1 << (N-1)); bit++){
      ll tmp = 0;
      for (int i = 0; i < N - 1; i++){
        tmp *= 10;
        tmp += S[i] - '0';
        if(bit & (1<<i)){
          out += tmp;
          tmp = 0;
        }
      }
      tmp *= 10;
      tmp += S.back() - '0';
      out += tmp;
    }
    cout << out << endl;
    return 0;
}