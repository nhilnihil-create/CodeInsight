#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

ll A[100002], B[100002];
bool active[100002];

int main(){
    ll N, K;
    cin >> N >> K;

    ll total = 0;
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i];
        if(A[i] <= K){
            total += B[i];
            active[i] = true;    
        }else{
            active[i] = false;
        }
    }

    ll logk = 0, K_copy = K;
    while(K_copy > 0){
        logk++;
        K_copy >>= 1;
    }

    ll ans = 0;
    for(int i=logk - 1;i>=0;i--){
        if((K>>i)&1){
            ll ans_cand = total;
            for(int j=0;j<N;j++){
                if(active[j] && ((A[j]>>i)&1) == 1){
                    ans_cand -= B[j];
                }
            }
            ans = max(ans, ans_cand);
        }else{
            for(int j=0;j<N;j++){
                if(((A[j]>>i)&1) == 1 && active[j]){
                    total -= B[j];
                    active[j] = false;
                }
            }
        }
    }
    ans = max(ans, total);

    cout << ans << endl;

    return 0;
}