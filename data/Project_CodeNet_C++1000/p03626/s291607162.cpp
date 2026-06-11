#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
  int N; cin >> N;
  string S[2]; cin >> S[0] >> S[1];

  int x_pos = 0;
  vector<int> ord;
  while(x_pos < N) {
    if (S[0][x_pos] == S[1][x_pos]) { ord.push_back(1); x_pos += 1; }
    else { ord.push_back(2); x_pos += 2; }
  }

  ll result;
  if(ord[0]==1) result = 3;
  else result = 6;
  for(int i=1; i<ord.size(); i++) {
    if (ord[i-1]==1 && ord[i]==1) result *= 2;
    else if (ord[i-1]==1 && ord[i]==2) result *= 2;
    else if (ord[i-1]==2 && ord[i]==1) result *= 1;
    else if (ord[i-1]==2 && ord[i]==2) result *= 3;
    result %= MOD;
  }

  cout << result << endl;
  return 0;
}