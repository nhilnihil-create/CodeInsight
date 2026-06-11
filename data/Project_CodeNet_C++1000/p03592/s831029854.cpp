#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } }

const int MOD = 1000000007;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (M * i + N * j - 2 * i * j == K) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
