


#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
#define DIV 1000000007
#define ll long long
using namespace std;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);

  loop(0, N, i) cin >> A[i];
  
  ll leastcost = -1;
  for (int bit=0; bit<(1<<N); bit++) {
    int valid = 0;
    vector<ll> D(N);
    for (int i=0; i<N; i++) {
      if (bit&(1<<i)) {
        D[i] = 1;
        valid++;
      }
    }
    if (valid != K) continue;

    ll cost = 0;
    ll maxsize = 0;
    loop(0, N, i) {
      if (D[i] == 0){
        maxsize = max(maxsize, A[i]);
        continue;
      } 

      if (A[i] <= maxsize) {
        cost += maxsize - A[i] + 1;
        maxsize = maxsize+1;
      } else {
        maxsize = A[i];
      }
    }
    if (leastcost == -1 || leastcost > cost) leastcost = cost;
  }
  print(leastcost);
}
