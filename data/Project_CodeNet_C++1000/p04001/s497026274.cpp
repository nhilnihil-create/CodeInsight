#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main() {
  ll S; cin >> S;
  vi num;
  ll len=0;
  while (S>0){
    num.push_back(S%10);
    S /=10;
  }
  len = num.size();
  ll ans =0;
  for (ll bit=0; bit<(1<<len-1); bit++){
    ll ssum = num[0];
    ll dig = 0;
    for (int i=0; i<len-1; i++){  //flg 1 = *, 0= +
      if(bit & (1<<i)) {
        dig++;
        ssum += num[i+1]*pow(10,dig);
      }
      else{
        ssum += num[i+1];
        dig = 0;
      }
    }
    ans += ssum;
  }
  cout << ans << endl;
}