#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long H, W;
vector<vector<long long>> cost_map(1000+1, vector<long long>(1000+1, 0));

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

  int N, a;
  cin >> N;
  int cnt_two = 0, cnt_four = 0, cnt_other = 0;
  for(int i = 0; i < N; ++i) {
    cin >> a;
    if(a%4 == 0) cnt_four++;
    else if(a%2 == 0) cnt_two++;
    else cnt_other++;
  }

  if(cnt_two == 0) {
    if(cnt_other <= cnt_four + 1) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    if(cnt_other <= cnt_four) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }

  return 0;
}
