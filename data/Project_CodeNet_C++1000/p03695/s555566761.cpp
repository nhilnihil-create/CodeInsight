#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  vector<bool> b(8,false);
  int tuyoi = 0;
  int n; cin >> n;
  rep(i, n){
    int rate; cin >> rate;
    int cnt = 0;
    for(int j=0; j<3200; j+=400){
      if(rate >= 3200){ tuyoi++; break; }
      if(j <= rate && rate < j+400) b[cnt] = true;
      cnt++;
    }
  }
  int iro = 0;
  rep(i, 8){
    if(b[i] == true) iro++;
  }
  if(iro==0)
    cout << 1 << " " << tuyoi << endl;
  else
    cout << iro << " " << iro+tuyoi << endl;
}