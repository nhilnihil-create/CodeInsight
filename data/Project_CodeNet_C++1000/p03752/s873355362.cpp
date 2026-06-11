#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <math.h>

int main(){

    // 入力
    int N, K; cin>>N>>K;
    vector<long> A(N);
    for (int n=0; n<N; n++) cin>>A[n];

    // bit全探索
    long ans = 1.0e+16;
    for (int ptn=0; ptn<(1<<N); ptn++){
        
        // 1がK以下のptnを弾く
        int tmp_cnt =0;
        for (int n=0; n<N; n++){
            if ( (ptn>>n)&1 ) tmp_cnt++;
        }
        if (tmp_cnt!=K) continue;
        
        // 探索
        long tmp_cost=0;
        vector<long> A_tmp = A;
        for (int n=1; n<N; n++){
            if (A_tmp[n-1] > A_tmp[n]) A_tmp[n] = A_tmp[n-1];
            if ( !((1<<n)&ptn) ) continue;
            if (A_tmp[n-1] < A_tmp[n]) continue;
            A_tmp[n] ++;
            tmp_cost += A_tmp[n] - A[n];
        }
        ans = min(ans, tmp_cost);
    }
    cout << ans << endl;
}