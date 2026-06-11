
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,M;
    cin >> N >> M;
    if(abs(N-M) > 1) { 
        cout << 0 << endl;
        return 0;
    }
    int INF = 1e9+7;
    int ans = 1;
    if(abs(N-M) == 0) {
        for(int i = 1; i <= N; i++) {
            ans*=i;
            ans%=INF;
        }
        for(int i = 1; i <= M; i++) {
            ans*=i;
            ans%=INF;
        }
        cout << ans*2%INF << endl;
    }
    else {
        for(int i = 1; i <= N; i++) {
            ans*=i;
            ans%=INF;
        }
        for(int i = 1; i <= M; i++) {
            ans*=i;
            ans%=INF;
        }
        cout << ans%INF << endl;
    }
}