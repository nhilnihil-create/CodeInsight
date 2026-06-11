#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N,C,K;
    cin >> N >> C >> K;
    vector<int>T(N);
    for(int i = 0; i < N; i++) {
        cin >> T[i];
    }
    sort(T.begin(),T.end());
    int cnt = 0,ans = 0,mi = T[0];
    for(int i = 0; i < N; i++) {
        if(mi+K >= T[i] && cnt+1 <= C) {
            cnt++;
        }
        else {
            ans++;
            cnt = 1;
            mi = T[i];
        }
    }
    ans++;
    cout << ans << endl;
}
