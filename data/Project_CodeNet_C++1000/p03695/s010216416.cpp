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
    int N; cin >> N;
    vector<int> R(9, 0);
    for (int i = 0; i < N; i++) {
        int r; cin >> r;
        if (r < 400) {
            R[0] = 1;
        } else if (r < 800) {
            R[1] = 1;
        } else if (r < 1200) {
            R[2] = 1;
        } else if (r < 1600) {
            R[3] = 1;
        } else if (r < 2000) {
            R[4] = 1;
        } else if (r < 2400) {
            R[5] = 1;
        } else if (r < 2800) {
            R[6] = 1;
        } else if (r < 3200) {
            R[7] = 1;
        } else {
            R[8]++;
        }
    }

    int mi = 0;
    for (int i = 0; i < 8; i++) if (R[i]) mi++;
    int ma = mi + R[8];
    if (mi == 0) mi = 1;

    cout << mi << " " << ma << endl;
    return 0;
}