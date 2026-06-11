#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  ll K;
  cin >> N >> K;
  vector<pii> v(N);

  for(int i = 0; i < N; i++){
    ll tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    v.at(i) = make_pair(tmp1,tmp2);
  }
  sort(v.begin(), v.end());
  cerr << v[0].first << " " << v.at(0).second << endl;

  ll num = 0;
  ll ans = 0;
  for(int i = 0; i < N; i++){
    if(num + v[i].second < K){
      num += v[i].second;
    } else { 
      ans = v[i].first;
      break;
    }
  }
  cout << ans << endl;
}
