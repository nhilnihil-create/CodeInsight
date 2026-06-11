#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N;
  ll x;
  cin >> N >> x;

  vector<ll> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  ll ans = 0;
  for(int i = 0; i < N-1; i++){
    ll tmp = 0;
    if(v[i] + v[i+1] >= x){
      if(v[i] <= x){
        // i+1だけ減らす
        tmp += v[i] + v[i+1] - x;
        v[i+1] -= tmp;
      } else {
        // iとi+1両方減らす i+1を優先して減らす
        tmp += v[i+1];
        v[i+1] = 0;
        tmp += v[i] - x;
        v[i] -= x;
      }
    }
    ans += tmp;
  }
  cout << ans << endl;

}
