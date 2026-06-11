#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  int domesticranking = 0, oversearanking = 0;
  REP(i, N) {
    char c = S[i];
    if (c == 'a') {
      if (domesticranking+oversearanking < A + B) {
        puts("Yes");
        domesticranking++;
      } else {
        puts("No");
      }
      
    } else if (c == 'b') {
      if (domesticranking+oversearanking < A + B && oversearanking < B) {
        puts("Yes");
        oversearanking++;
      } else {
        puts("No");
      }
     
    } else {
      puts("No");
    }
  }
}