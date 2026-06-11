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
    int N; cin >> N;
    vector<ll> a(N);
    int teven = 0, feven = 0, odd = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i] % 4 == 0) feven++;
        else if(a[i] % 2 == 0) teven++;
        else odd++;
    }
    string ans;
    if(teven != 0) {
        if(feven >= odd) ans = "Yes";
        else ans = "No";
    }
    else {
        if(feven >= odd - 1) ans = "Yes";
        else ans = "No";
    }
    cout << ans << endl;
    return 0;
}