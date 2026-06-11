#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, cnt=0;
  string S, T;
  cin >> N >> S >> T;
  rep(i, N){
    if(S.substr(S.size()-1-i, i+1)==T.substr(0,i+1)) cnt=i+1;
  }
  cout << max(N,(int)(S.size())*2-cnt) << endl;
}