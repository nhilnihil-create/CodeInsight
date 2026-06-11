#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

long power(long a, long b) {
    return b ? power(a*a%MOD, b/2) * (b%2?a:1)%MOD:1;
}

long perm(int N, int K) {
    long x = 1;
    for(int i = 1; i <= K; i++) x = x * (N-i+1) % MOD;
    return x % MOD;
}

long comb(int N,int K) {
    long x = 1, y = 1;
    for(int i = 1; i <= K; i++) {
        x = x * (N-i+1) % MOD;
        y = y * i % MOD;
    }
    return x * power(y, MOD-2) % MOD;
}

bool isprime(int n) {
    if(n < 2) return false;
    for(int i = 2; i*i <= n; ++i) {
        if (n % i ==  0) return false;
    }
    return true;
}

void dfs(const vector<vector<int> > &G, int v, vector<int> &seen) {
    seen[v] = true;

    for(int next_v : G[v]) {
        if(seen[next_v]) continue;
        dfs(G, next_v, seen);
    }
}

void yes() { cout << "Yes" << endl;}
void no() { cout << "No" << endl;}

int main() {
  int n, tmp, count = 1;
  cin >> n;
  vector<int> button(n);
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    button[i] = tmp;
  }
  int i = 0;
  while (button[i] != 2) {
    if (count > 1000000) {
      count = -1;
      break;
    }
    i = button[i] - 1;
    count++;
  }
  cout << count << endl;
}