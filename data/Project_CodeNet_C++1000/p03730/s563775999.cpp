#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int gcd(int n, int m) {
    if(n < m) swap(n, m);
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int lcm(int n, int m) {
    return n * m / gcd(n, m);
}

int main() {
    int A, B, C; cin >> A >> B >> C;
    vector<int> q;
    set<int> s;
    int hoge = A;
    while(hoge != lcm(A, B)) {
        if(!s.count(hoge % B)) q.push_back(hoge % B);
        s.insert(hoge % B);
        hoge += A;
    }
    sort(q.begin(), q.end());
    vector<vector<int>> dp(q.size() + 1, vector<int>(C + 1));
    for(int i = 0; i <= q.size(); i++) {
        dp[i][0] = 1;
        if(i == 0) continue;
        for(int j = q[i - 1]; j <= C; j += q[i - 1]) dp[i][j] = 1;
    }
    for(int i = 1; i <= q.size(); i++) {
        for(int j = 0; j <= C; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    if(dp[q.size()][C]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}