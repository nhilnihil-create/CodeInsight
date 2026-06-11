#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  int a;
  deque<int> b;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (n%2==0) {
      if (i%2==0) {
        b.push_back(a);
      }
      else {
        b.push_front(a);
      }
    }
    else {
      if (i%2==0) {
        b.push_front(a);
      }
      else {
        b.push_back(a);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    cout << b[i];
    if(i != n-1) {
      cout << ' ';
    }
    else {
      cout << endl;
    }
  }

  return 0;
}
