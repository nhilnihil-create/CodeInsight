#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  int N; cin >> N;
  int A[N]; rep(i,N) cin >> A[i];

  ll result = A[0]-1, num = 2;
  for (int i=1; i<N; i++) {
    if (A[i]==num) num++;
    else result += (A[i]-1)/num;
  }
  cout << result << endl;
  return 0;
}