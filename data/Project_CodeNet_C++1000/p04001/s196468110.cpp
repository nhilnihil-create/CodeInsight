#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main(){
  string S;
  cin >> S;
  int N = S.size();
  ll sum = 0;
  for(int bit=0;bit<(1<<(N-1));bit++){
    ll ps = 0;
    for(int i=0;i<N;i++){
      ps = ps * 10 + S.at(i) - '0';
      if(bit & (1<<i)){
        sum += ps;
        ps = 0;
      }
    }
    sum += ps;
  }
  cout << sum << endl;
  return 0;
}