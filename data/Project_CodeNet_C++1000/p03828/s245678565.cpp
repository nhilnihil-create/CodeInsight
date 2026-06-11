#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool is_Prime(int n) {
  if(n == 2) return true;
  if(n < 2 || n % 2 == 0) return false;
  for(int i = 3; i*i <= n; i+=2) {
    if(n % i == 0) return false;
  }
  return true;
}

const long long INF = 1LL << 60;
const long long P = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  long long ans = 1;
  for(int i = 1; i <= n; i++) {
    if(is_Prime(i)) {
      v.push_back(i);
    }
  }
  long long count;
  for(int i = 0; i < v.size(); i++) {
    count = 0;
    int tmp = v[i];
    for(int j = v[i]; j <= n;) {
      count += n / j;
      j = j*tmp;
    }
    ans *= count+1;
    ans %= P;
  }
  cout << ans << endl;
  return 0;
}