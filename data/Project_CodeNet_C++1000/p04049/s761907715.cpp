#include <bits/stdc++.h>

using namespace std;


vector<int> g[2000];

int dfs(int start, int cur, int prev, int tot, int lim) {
    int ans = tot > lim;
    for (auto &&c: g[cur]) {
        if (prev != c) ans += dfs(start, c, cur, tot + 1, lim);
    }
    return ans;
}

void solve(long long N, long long K, vector<long long> A, vector<long long> B) {
    vector< pair<int,int> > es;
    for (int i = 0; i < A.size(); i++) {
        A[i]--;
        B[i]--;
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
        es.emplace_back(A[i], B[i]);
    }

    int ans = 1e9;
    if( K % 2 ){
        for (auto &e : es) {
            int sub = 0;
            for( int j : {e.first, e.second}){
                sub += dfs(j, j, e.first ^ e.second ^j , 0, (K-1)/2);
            }
            ans = min(ans, sub);
        }
    }else{
        for(int i = 0 ; i < N ; i++){
            ans = min(ans, dfs(i, i, -1, 0, K / 2));
        }
    }
    cout << ans << endl;

}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    vector<long long> A(N - 1);
    vector<long long> B(N - 1);
    for (int i = 0; i < N - 1; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
    }
    solve(N, K, A, B);
    return 0;
}

