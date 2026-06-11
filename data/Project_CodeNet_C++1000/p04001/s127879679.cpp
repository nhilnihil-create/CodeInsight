#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;
#define all(v) v.begin(), v.end()


int main(){
  string S;
  ll ans=0;
  cin >> S;
  for (int tmp = 0; tmp < (1 <<(S.size()-1)); tmp++) {
    bitset<9> s(tmp);
    ll t=(S.at(S.size()-1)-'0'),x=1;
    rep(i,S.size()-1){
      if(s.test(i)){
        ans+=t;
        x=1;
        t=S.at(S.size()-2-i)-'0';
      }else{
        t+=(S.at(S.size()-2-i)-'0')*(ll)pow(10,x);
        x++;
      }
    }
    ans+=t;
  }
  cout << ans << endl;
    
}