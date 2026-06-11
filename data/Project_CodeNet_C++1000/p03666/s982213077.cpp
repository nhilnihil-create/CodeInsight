#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
signed main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    N--;
    for(int n = 0; n <= N; n++) {
        int m = N - n;
        int min = A + C * n - D * m;
        int max = A + D * n - C * m;
        if(min <= B && B <= max) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
