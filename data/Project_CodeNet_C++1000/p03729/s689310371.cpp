#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    if (A[SZ(A) - 1] == B[0] && B[SZ(B) - 1] == C[0]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
