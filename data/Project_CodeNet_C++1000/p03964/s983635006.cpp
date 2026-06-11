#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> t(n), a(n);
  for(int i = 0; i < n; i++) cin >> t.at(i) >> a.at(i);
  
  ll nowt = 1, nowa = 1;
  for(int i = 0; i < n; i++){
    ll t1, a1, t2, a2;
    if(nowt % t.at(i) == 0){
      t1 = nowt;
      a1 = a.at(i) * (t1 / t.at(i));
    }
    else{
      t1 = (nowt / t.at(i) + 1) * t.at(i);
      a1 = a.at(i) * (t1 / t.at(i));
    }
    if(nowa % a.at(i) == 0){
      a2 = nowa;
      t2 = t.at(i) * (a2 / a.at(i));
    }
    else{
      a2 = (nowa / a.at(i) + 1) * a.at(i);
      t2 = t.at(i) * (a2 / a.at(i));
    }
    
    if(a1 < nowa){
      nowt = t2;
      nowa = a2;
    }
    else if(t2 < nowt){
      nowt = t1;
      nowa = a1;
    }
    else{
      if(t1 + a1 < t2 + a2){
        nowt = t1;
        nowa = a1;
      }
      else{
        nowt = t2;
        nowa = a2;
      }
    }
  }
  
  cout << nowt + nowa << '\n';
}