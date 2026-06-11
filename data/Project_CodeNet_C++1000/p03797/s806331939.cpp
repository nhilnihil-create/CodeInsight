#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int INF = 1e9;

int main(int argc, const char * argv[]) {
  ll N, M;
  cin >> N >> M;

  ll cnt = min(N, M /2);
  M -= cnt * 2;
  cnt += M / 4;
  cout << cnt << endl;
  return 0;
}
