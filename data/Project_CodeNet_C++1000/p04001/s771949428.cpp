#include <bits/stdc++.h>
using namespace std;
#define rep0(i, a) for(int i=0;i < (int)(a); i++)
#define rep(i, a, b) for(int i=(a);i < (b); i++)

int main(){
  string S;
  cin >> S;
  int i,k,n;
  int64_t ret, tmp, cache;
  ret = 0;
  n = S.size();
  rep0(i, (1<<n-1)){
    tmp = 0;cache=S[0] - '0';
    bitset<10> bit(i);
    rep0(k, n-1){
      if (bit.test(k)){
        tmp += cache;
        cache=(S.at(k+1) - '0');
      }
      else{
        cache *= 10;
        cache += (S.at(k+1) - '0');
      }
    }
    tmp += cache;
    ret += tmp;
  }
  cout << ret << endl;
}