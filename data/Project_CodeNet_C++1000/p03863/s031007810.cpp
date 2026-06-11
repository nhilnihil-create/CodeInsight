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
    string S;
    cin >> S;
    
    if (S[0] == S[SZ(S) - 1]) {
        if (SZ(S) & 1) cout << "Second\n";
        else cout << "First\n";
    } else {
        if (SZ(S) & 1) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}
