#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  ll ans = 0;

  string x;
  cin >> x;

  for(int i = 0; i < (1 << x.size()-1); i++){
    ll tmp_sum = 0;
  	bitset<10> bit(i);
    rep(j, x.size()-1){
      if(bit.test(j)){
        ans += (int)(x[j]-'0') + tmp_sum * 10;
        tmp_sum = 0;
      } else {
        tmp_sum *= 10;
        tmp_sum += (int)(x[j]-'0');
      }  
    }
    ans += (int)(x[x.size()-1]-'0') + tmp_sum * 10;
  }
  cout << ans << endl;
}