#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll A,B,C,D; cin >> A >> B >> C >> D;
  ll N; cin >> N;
  
  // 2Lコスパ最強の方法
  vector<ll> v2l(4);
  v2l[0] = A * 8;
  v2l[1] = B * 4;
  v2l[2] = C * 2;
  v2l[3] = D;
  sort(v2l.begin(), v2l.end());
  
  ll v2 = v2l[0];

  vector<ll> v1l(3);
  v1l[0] = A * 4;
  v1l[1] = B * 2;
  v1l[2] = C;
  
  sort(v1l.begin(), v1l.end());
  ll v1 = v1l[0];
  
  cerr << v1 << " " << v2 << endl;
  
  ll ans = 0;
  ans += v2 * (N/2);
  ans += v1 * (N%2);
  cout << ans << endl;

}