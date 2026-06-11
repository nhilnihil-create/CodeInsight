#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { return (a%b == 0) ? b : gcd(b, a%b); }
inline int fac(int n) { return (n==0) ? 1 : n * fac(n - 1); }

int main() {
    int N;
    cin >> N;
    int a[N];
    bool rate_num[9] = {};
    int n = 0;
    int c = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        for (int j = 0; j < 8; j++) {
            if (400 * j <= a[i] && a[i] < 400 * (j + 1)) {
                if (rate_num[j] == false) {
                    c++;
                    rate_num[j] = true;
                }
            }
        }
        if (400 * 8 <= a[i]) {
            n++;
        }
    }

    int max = n + c;
    int min = (c == 0) ? 1 : c;

    cout << min << " " << max << endl;

    return 0;
}