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

int main() {
    ll N, T; cin >> N >> T;
    vector<ll> t(N);
    for(int i = 0; i < N;i++) cin >> t[i];
    ll sum = 0, time = 0;
    for(int i = 1; i < N; i++) sum += min(T, t[i] - t[i - 1]);
    sum += T;
    cout << sum << endl;
    return 0;
}