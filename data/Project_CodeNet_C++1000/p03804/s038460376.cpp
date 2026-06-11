#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> p;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll dx[] = { 1,0 };
ll dy[] = { 0,1 };

bool judge(vector<string> A, vector<string> B, ll a, ll b);
ll N, M, x, y;

int main() {


    cin >> N >> M;

    vector<string>A(N), B(M);

    rep(i, N) {
        cin >> A[i];
    }

    rep(i, M) {
        cin >> B[i];
    }

    x = B.size();
    y = B[0].size();


    bool ans = false;

    rep(i, N - x + 1) {
        rep(j,  A[0].size() - y + 1) {
            if (A[i][j] == B[0][0] && A[i + x - 1][j + y - 1] == B[x - 1][y - 1]) {
                if (judge(A, B, i, j)) {
                    ans = true;
                    break;
                }
            }
        }
    }

    if (ans) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}

bool judge(vector<string> A, vector<string> B, ll a, ll b) {
    bool ans = true;
    rep(i, M) {
        rep(j, y) {
            if (A[i + a][j + b] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}