#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, M; cin >> N >> M;
    vector<int> X(N);
    vector<int> X_count(100001);
    vector<int> XmodM_count(100001);
    vector<int> XmodM_HitoriBocchi(100001);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        X_count[X[i]]++;
    }
    
    for (int i = 0; i < 100001; i++) {
        if (X_count[i] % 2) {
            XmodM_HitoriBocchi[i % M]++;
        }
        XmodM_count[i % M] += X_count[i];
    }
    
    int ans = XmodM_count[0]/2;
    int limit = M/2;
    if (M%2 == 0) {
        ans += XmodM_count[M/2]/2;
        limit = M/2-1;
    }
    for (int i = 1; i <= limit; i++) {
        int cnt = min(XmodM_HitoriBocchi[i], XmodM_HitoriBocchi[M-i]);
        ans += cnt;
        XmodM_HitoriBocchi[i] -= cnt;
        XmodM_HitoriBocchi[M-i] -= cnt;
        XmodM_count[i] -= cnt;
        XmodM_count[M-i] -= cnt;
        cnt = min(min(XmodM_count[i], XmodM_count[M-i]), max(XmodM_HitoriBocchi[i], XmodM_HitoriBocchi[M-i]));
        ans += cnt;
        if (XmodM_HitoriBocchi[i] != 0) XmodM_HitoriBocchi[i] -= cnt;
        else XmodM_HitoriBocchi[M-i] -= cnt;
        XmodM_count[i] -= cnt;
        XmodM_count[M-i] -= cnt;
        ans += max((XmodM_count[i] - XmodM_HitoriBocchi[i])/2 + (XmodM_count[M-i] - XmodM_HitoriBocchi[M-i])/2, 0);
    }
    cout << ans << endl;
}
