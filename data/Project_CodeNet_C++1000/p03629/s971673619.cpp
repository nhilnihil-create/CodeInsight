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
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    string A;
    cin >> A;
    
    vector<vector<int>> S(26);
    REP(i, SZ(A)) S[A[i] - 'a'].push_back(i);
    REP(i, 26) S[i].push_back(SZ(A));
    vector<int> T(SZ(A) + 2, 1001001001);
    T[SZ(A) + 1] = 0;
    T[SZ(A)] = 1;
    for (int i = SZ(A) - 1; i >= 0; --i) {
        REP(j, 26) {
            T[i] = min(T[i], T[*lower_bound(ALL(S[j]), i) + 1] + 1);
        }
    }
    
    string ans;
    int now = 0;
    while (now < SZ(A) + 1) {
        REP(i, 26) {
            if (T[*lower_bound(ALL(S[i]), now) + 1] == T[now] - 1) {
                now = *lower_bound(ALL(S[i]), now) + 1;
                ans.push_back('a' + i);
                break;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
