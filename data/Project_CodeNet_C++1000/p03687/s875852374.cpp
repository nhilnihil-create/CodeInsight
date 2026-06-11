// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  string s;
  ll ans = 10000000000000;
  cin >> s;
  for(char c='a';c<='z';c++){
    string cp;
    cp = s;
    ll cnt = 0;
    while(true){
      bool can = true;
      string tmp;
      ll n = cp.size();
      for(int i=0;i<n;i++){
        if(cp[i]!=c){
          can = false;
          break;
        }
      }
      if(can){
        break;
      }
      cnt++;
      for(int i=0;i<n-1;i++){
        if(cp[i]==c||cp[i+1]==c){
          tmp += c;
        }else{
          tmp += cp[i];
        }
      }
      cp = tmp;
    }
    ans = min(ans,cnt);
  }
  cout << ans << endl;
}
