#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> out;
    ll cnt = 0;
    for (int i = 0; i < M; i++) {
      ll a, b;
      cin >> a >> b;
      if(a==1){
        out.insert(b);
        cnt++;
      }
      if (b == N){
          out.insert(a);
          cnt++;
      }
    }
    if(cnt==out.size()){
      cout << "IMPOSSIBLE" << endl;
    }
    else{
      cout << "POSSIBLE" << endl;
    }
    return 0;
}