#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
    ll N, M;    cin >> N;
    VL T(N);    ll sum = 0;
    rep(i,0,N){        
        cin >> T[i];
        sum += T[i];
    }
    cin >> M;    VL P(M), X(M);
    rep(i,0,M){        
        cin >> P[i] >> X[i];
    }

    ll ans = sum;
    rep(i,0,M){
        ans = sum;
        ans += X[i] - T[P[i]-1];
        cout << ans << endl;
    }
    return 0;
}