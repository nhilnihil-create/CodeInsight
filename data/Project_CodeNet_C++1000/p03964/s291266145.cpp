#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  ll t,a;
  cin >> n >> t >> a;
  rep(i,1,n){
    ll vt,va;
    cin >> vt >> va;
    if(va >= a && vt >= t){a = va;t = vt;}
    else{
      ll bt,ba;
      bt = t/vt;
      if(t%vt != 0) bt++;
      ba = a/va;
      if(a%va != 0) ba++;
      a = max(bt,ba)*va;
      t = max(bt,ba)*vt;
      //cout << t << " " << a << endl;
    }
  }
  cout << t+a << endl;
}