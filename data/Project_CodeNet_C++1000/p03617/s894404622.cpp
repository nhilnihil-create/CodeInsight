#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long Q, H, S, D, N;
    cin >> Q >> H >> S >> D;
    cin >> N;

    long long p_D, p_S, p_H, p_Q;

    p_S = S*N;
    p_H = H*N*2;
    p_Q = Q*N*4;
    if(N % 2 == 0){
        p_D = (N/2)*D;
    }else{
        p_D = (N/2)*D + min({Q*4, H*2, S});
    }

    cout << min({p_D, p_S, p_Q, p_H}) << endl;
    return 0;
}