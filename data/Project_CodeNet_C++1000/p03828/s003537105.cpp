#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 1001;
bool isPrime[MAX];
 
void aryPrime() {
  for (int i = 0; i < MAX; i++) isPrime[i] = true;
  isPrime[0] = false;
  isPrime[1] = false;
  int n = sqrt(MAX);
  for (int i = 2; i <= n; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * 2; j < MAX; j += i) {
      isPrime[j] = false;
    }
  }
}

int main() {
    int N;
    cin >> N;
    ll mod = pow(10, 9) + 7;
    if (N == 1) {
        cout << "1\n";
        return 0;
    }
    aryPrime();
    vector<int> p;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) p.push_back(i);
    }
    ll a[p.size()]{};
    for (int i = 0; i < p.size(); i++) {
        for (int j = 2; j <= N; j++) {
            int t = j;
            while (t % p[i] == 0) {
                a[i]++;
                t /= p[i];
            }
        }
    }
    ll ans = 1;
    for (ll i : a) {
        ans *= (i + 1);
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}