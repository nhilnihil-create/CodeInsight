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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp - 1;
    }
    int cnt = 1;
    int target = a[0];
    for (;;)
    {
        if (target == 1) {
            break;
        }
        target = a[target];
        cnt++;
        if (cnt > n) {
            cnt = -1;
            break;
        }
    }

    cout << cnt << endl;
    return 0;
}
