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
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b;
    for(int i = 0; i < n; i += 2) {
        b.push_back(a[i]);
    }
    reverse(b.begin(), b.end());
    for(int i = 1; i < n; i += 2) {
        b.push_back(a[i]);
    }
    if(n % 2 == 0) reverse(b.begin(), b.end());
    for(int i = 0; i < n; i++) {
        if(i != n - 1) cout << b[i] << ' ';
        else cout << b[n - 1] << endl;
    }
    return 0;
}