#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, A[100000];
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> A[i];
        A[i]--;
    }

    int64_t no_skip_cost = 0;
    int64_t imos[200002] = {0};

    for(int i=0; i<N-1; i++){
        int s = A[i], t = A[i+1];
        if(s > t) t += M;
        int d = t-s;
        no_skip_cost += d;
        imos[s+2] += 1;
        imos[t+1] += -d;
        imos[t+2] += d-1;
    }
    for(int t=0; t<2; t++) for(int i=1; i<2*M; i++) imos[i] += imos[i-1];

    int64_t save_cost = 0;
    for(int i=0; i<M; i++) save_cost = max(save_cost, imos[i] + imos[M+i]);
    int64_t ans = no_skip_cost - save_cost;
    cout << ans << endl;
    return 0;
}
