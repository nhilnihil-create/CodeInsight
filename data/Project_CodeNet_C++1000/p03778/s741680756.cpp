#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int W, a, b;
    cin >> W >> a >> b;
    if (a <= b) cout << max(0, b - (a + W)) << endl;
    else cout << max(0, a - (b + W)) << endl;
}