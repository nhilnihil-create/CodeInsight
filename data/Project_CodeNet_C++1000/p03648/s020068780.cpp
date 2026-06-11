#include <iostream>
#define REP(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
int main(){
  long long K;
  cin >> K;
  cout << 50 << endl;
  REP(i,50){
    if(i) cout << ' ';
    if(i >= K % 50){ 
      ll ans = 49 + 50 * (K/50) - (K - (K / 50 ));
      cout << ans;
    }else{
      ll ans = 49 + 50 * (K/50 + 1) - ( K - (K / 50 + 1 ));
      cout << ans;
    }/// ＋１回ーされる数
  }
  return 0;
}
