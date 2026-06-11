#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int64_t L, T;
    cin >> N >> L >> T;
    vector<int64_t> X(N), W(N);
    for(int i=0; i<N; i++) cin >> X[i] >> W[i];

    int z0 = 0;
    for(int i=0; i<N; i++) if(W[i] != W[0]){
        if(W[0] == 1){
            int64_t d = (X[i] - X[0] + L) % L;
            int t = (2*T-1+L-d)/L;
            z0 = (z0 + t) % N;
        }else{
            int64_t d = (X[0] - X[i] + L) % L;
            int t = (2*T-1+L-d)/L;
            z0 = (z0 - t%N + N) % N;
        }
    }
    
    vector<vector<int64_t>> poss(N);
    for(int i=0; i<N; i++){
        int64_t p = (X[i] + T*(W[i] == 1 ? 1 : -1)%L + L) % L;
        poss[i] = {p, W[i], i};
    }
    vector<int> ans(N);
    sort(poss.begin(), poss.end());
    for(int s=0; s<N; s++) if(poss[s][2] == 0){
        for(int i=0; i<N; i++) ans[(i-s+z0+N)%N] = poss[i][0];
    }
    for(int i=0; i<N; i++) cout << ans[i] << endl;
}