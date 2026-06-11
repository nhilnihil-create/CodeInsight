#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { if (a%b == 0) { return b; } else { return gcd(b, a%b); } }

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int c[m], d[m];
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }

    for (int i = 0; i < n; i++) {
        int min = 1000000000;
        int nearest;
        for (int j = 0; j < m; j++) {
            int dis = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (dis < min) {
                min = dis;
                nearest = j + 1;
            }
        }
        cout << nearest << endl;
    }

    return 0;
}