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
    int n;
    cin >> n;
    vector<int> a(n);
    int b[100010] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }

    int max = 0;
    for (int i = 1; i < 100000; i++) {
        int temp = b[i - 1] + b[i] + b[i + 1];
        if (max < temp) {
            max = temp;
        }
    }

    cout << max << endl;
    return 0;
}