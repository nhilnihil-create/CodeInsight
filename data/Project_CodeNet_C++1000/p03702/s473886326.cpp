#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

ll N, A, B, h[100010];

bool isOK(ll T){
    ll count = 0;
    for(int i = 0; i < N; i++){
        if(h[i] <= B*T) continue;
        else    count += (h[i] - B*T- 1)/(A-B) + 1;
    }
    
    return count <= T;
}

int main(){
    cin >> N >> A >> B;
    for(int i = 0; i < N; i++) cin >> h[i];

    ll ng = 0;
    ll ok = 1000000000;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng)/2;

        if(isOK(mid))   ok = mid;
        else    ng = mid;
    }
    cout << ok << "\n";
    return 0;
}