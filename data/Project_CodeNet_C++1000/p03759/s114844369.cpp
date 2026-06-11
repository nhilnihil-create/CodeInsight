#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string YES = "YES";
const string NO = "NO";

void solve(long long a, long long b, long long c) {
    cout << ((b-a == c - b) ? YES : NO) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long a;
  scanf("%lld", &a);
  long long b;
  scanf("%lld", &b);
  long long c;
  scanf("%lld", &c);
  solve(a, b, c);
  return 0;
}
