#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int Q,H,S,D;
    int N;
    cin >> Q >> H >> S >> D >> N;
    // Q*4 Q*2+H H*2 S = 1L
    int mi = min({Q*4,Q*2+H,H*2,S});
    if(mi*2 >= D) {
        cout << N/2*D+N%2*mi << endl;
    }
    else {
        cout << N*mi << endl;
    }
}
