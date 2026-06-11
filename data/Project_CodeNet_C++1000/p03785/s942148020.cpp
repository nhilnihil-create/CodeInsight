#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, C,K ;cin >> N >> C >> K;
    vector<ll> T(N);
    for (ll i = 0; i < N; i++) {
        cin >> T[i];
    }

    sort(ALL(T));

    ll prebus = T[0];
    ll waiting = 1;
    ll ans = 0;
    for (ll i = 1; i < N; i++) {
        if(T[i] > prebus + K){
            ans++;
            waiting = 1;
            prebus = T[i];
        }
        else if(waiting == C){
            ans++;
            waiting = 1;
            prebus = T[i];
        }
        else{
            waiting++;
        }
    }

    if(waiting > 0){
        ans++;
    }
    printf("%lld\n", ans);

}
