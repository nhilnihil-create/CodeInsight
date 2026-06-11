#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N, K; cin >> N >> K;
    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    ll ans = INF;
    for(int b = 0; b < (1<<N); b++){
        bitset<15> B = b;
        if(B.count() != K) continue;
        ll MAX = A[0], SUM = 0;
        for(int i = 0; i < N; i++){
            if(B[i]){
                if(i != 0) {
                    SUM += max(0LL, MAX-A[i]+1);
                    MAX = max(MAX+1, A[i]);
                }
            }
            else{
                MAX = max(MAX, A[i]);
            }
            

        }
        ans = min(ans, SUM);
    }
    cout << ans << endl;
} 
