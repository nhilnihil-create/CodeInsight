#include <iostream>
#include <map>
using namespace std;
#define MOD 1000000007

void solve(){
  int n; cin >> n;
  map<int,int> mp;
  int flag = 0;
  for(int i = 0; i < n; ++i) {
	int tmp; cin >> tmp;
    mp[tmp]++;
    if(n%2 == 0 && tmp%2==0){
      cout << 0 << endl;
      return;
    }
    if(n%2==1 && tmp%2==1){
      cout << 0 << endl;
      return;
    }
    if(mp[tmp] >2 || mp[0] > 1) {
      cout << 0 << endl;
      return ;
    }
  }
  long long ans = 1;
  
	for(int i = 0; i < n/2; ++i){
      ans *= 2;
      ans %= MOD;
    }
    cout << ans << endl;
  }


int main(){
  solve();
  return 0;
}
