#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    string S,T;
    cin >> N >> S >> T;
    for(int i = N; i >= 0; i--) {
        if(S.substr(N-i,i) == T.substr(0,i)) {
            cout << N*2-i << endl;
            return 0;
        }
    }
}
