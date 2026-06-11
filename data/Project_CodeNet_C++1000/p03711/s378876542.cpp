#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int x, y; cin >> x >> y;
    vector<int> A(13);
    A[1] = 1; A[3] = 1; A[5] = 1; A[7] = 1; A[8] = 1; A[10] = 1; A[12] = 1;
    A[4] = 2; A[6] = 2; A[9] = 2; A[11] = 2;
    A[2] = 3;
    if (A[x] == A[y]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}