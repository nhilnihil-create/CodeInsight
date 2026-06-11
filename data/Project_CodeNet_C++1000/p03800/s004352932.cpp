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
    string S;
    cin >> N >> S;
    // 0 = 狼　1 = 羊
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            vector<int>ans(N);
            ans[0] = i;
            ans[1] = j;
            for(int k = 2; k < N; k++) {
                if((S[k-1] == 'o' && ans[k-1] == 1) || (S[k-1] == 'x' && ans[k-1] == 0)) {
                    ans[k] = ans[k-2];
                }
                else {
                    ans[k] = (ans[k-2]^1);
                }
            }
            if(((S[0] == 'o' && ans[0] == 1) || (S[0] == 'x' && ans[0] == 0)) && ans[1] != ans[N-1]) {
                continue;
            }
            if(((S[0] == 'x' && ans[0] == 1) || (S[0] == 'o' && ans[0] == 0)) && ans[1] == ans[N-1]) {
                continue;
            }
            if(((S[N-1] == 'o' && ans[N-1] == 1) || (S[N-1] == 'x' && ans[N-1] == 0)) && ans[0] != ans[N-2]) {
                continue;
            }
            if(((S[N-1] == 'x' && ans[N-1] == 1) || (S[N-1] == 'o' && ans[N-1] == 0)) && ans[0] == ans[N-2]) {
                continue;
            }
            for(int i = 0; i < N; i++) {
                if(ans[i]) {
                    cout << "S";
                }
                else {
                    cout << "W";
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
