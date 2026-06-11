#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    vector<vector<bool>> dp1(N+2, vector<bool>(K+1, false));
    dp1[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp1[i-1][j]) {
                dp1[i][j] = true;
                dp1[i][min(K, j+a[i])] = true;
            }
        }
    }
    
    int ans = 0;
    set<int> s;
    s.insert(0);
    for (int i = N; i >= 1; i--) {
        bool check = true;
        for (int j = 0; j <= K; j++) {
            if (!dp1[i-1][j]) continue;
            auto it = s.lower_bound(K-j-a[i]);
            if (it != s.end() && (*it) < K-j) {
                check = false;
                break;
            }
        }
        if (check) ans++;
        vector<int> nxt;
        auto it2 = s.begin();
        while (it2 != s.end()){
            nxt.push_back(min(K, (*it2)+a[i]));
            it2++;
        }
        for (int n : nxt) s.insert(n);
    }
    cout << ans << endl;
    return 0;
}
