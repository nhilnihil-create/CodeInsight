#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> cnt(100002, 0);
    vector<int> mod(M, 0);
    vector<int> p(M, 0);
    
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        X[i] = n;
        mod[n%M]++;
        if (cnt[n] == 1) {
            cnt[n]--;
            p[n%M]++;
        }else{
            cnt[n]++;
        }
    }
    
    int ans = 0;
    ans += mod[0] / 2;
    if (M % 2 == 0) ans += mod[M/2] / 2;
    
    for (int i = 1; i <= (M-1)/2; i++) {
        int j = M - i;
        int t = max(mod[i] - p[i] * 2, mod[j] - p[j] * 2);
        t = min(t, min(mod[i], mod[j]));
        int u = min((mod[i] - t) / 2, p[i]);
        int v = min((mod[j] - t) / 2, p[j]);
        ans += t+u+v;
    }
    cout << ans << endl;
}