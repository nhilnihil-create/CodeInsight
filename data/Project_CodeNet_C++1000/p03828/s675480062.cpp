#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 10007;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[1005];
signed main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int X = i;
        for(int j = 2; j*j <= i; j++) {
            if(X%j == 0) {
                int res = 0;
                while(X%j == 0) {
                    X/=j;
                    res++;
                }
                cnt[j]+=res;
            }
        }
        if(X != 1) {
            cnt[X]++;
        }
    }
    int ans = 1;
    for(int i = 1; i <= N; i++) {
        ans*=cnt[i]+1;
        ans%=INF;
    }
    cout << ans << endl;
}
