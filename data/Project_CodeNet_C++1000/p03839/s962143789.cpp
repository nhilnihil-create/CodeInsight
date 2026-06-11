#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;
template<class T> inline bool chmax(T &a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    vector<long long> sum(N + 1, 0);
    vector<long long> plu(N + 1, 0);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum[i + 1] = sum[i] + A[i];
        plu[i + 1] = plu[i] + max(A[i], 0LL);
    }
    
    long long ans = -INF;
    
    for(int i = 0; i + K <= N; i++){
        long long res = plu[N];
        res += max(sum[i + K] - sum[i], 0LL);
        res -= plu[i + K] - plu[i];
        chmax(ans, res);
    }
    
    cout << ans << endl;
    return 0;
}