#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000000+7;

using ll = long long int;
ll RepeatSquaring(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2);
        return t*t % MOD;
    }
    return N * RepeatSquaring(N, P-1);
}

int main() {
  long n;
  cin >> n;
  vector<int>data(n,0);
  for(long i = 0;i < n;i++){
    long a;
    cin >> a;
    data[a]++;
  }
  if(n%2 == 0){
    for(long i = 1;i < n;i += 2){
      if(data[i] != 2){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  else{
    for(long i = 0;i < n;i += 2){
      if(i == 0){
        if(data[i] != 1){
          cout << 0 << endl;
          return 0;
        }
      }
      else if(data[i] != 2){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  ll ans = RepeatSquaring(2,n/2);
  cout << ans << endl;
}
