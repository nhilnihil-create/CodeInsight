#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll N = a.size();
    vector<ll> b(n);

    if(true){
      b[N / 2] = a[0];
      ll idx = 0;
      for (int i = N - 1; i > 0; i -= 2) {
        b[idx] = a[i];
        idx++;
      }
      idx = N / 2 + 1;
      ll j = 0;
      if (N % 2 == 1)
        j = 1;
      else j = 2;
      for (; j < N; j += 2) {
        b[idx] = a[j];
        idx++;
      }
    }
    for (int i = 0; i < N; i++){
      cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}