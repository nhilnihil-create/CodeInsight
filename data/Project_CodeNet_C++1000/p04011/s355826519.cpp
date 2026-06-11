#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    int ans = 0;
    if (N > K) ans += Y * (N - K);
    ans += X * min(N, K);
    cout << ans << endl;
}