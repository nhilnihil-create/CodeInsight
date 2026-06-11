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
  ll n,k,need;
  cin >> s >> k;
  n = s.size();
  for(auto &c:s){
    need = 'z' - c + 1;
    if(c != 'a' && need<=k){
      c = 'a';
      k -= need;
    }
  }
  k %= 26;
  for(int i=0;i<k;i++){
    if(s[n-1]=='z') s[n-1] = 'a';
    else s[n-1]++;
  }
  cout << s << endl;
}
