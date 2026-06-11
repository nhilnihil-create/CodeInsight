#include<bits/stdc++.h>
#define MAX 100000000
using ll = long long;
using namespace std;

int main(){
    ll Q, H, S, D; cin >> Q >> H >> S >> D;
    ll N;  cin >> N;

    ll ans =0;
    H = min(H, 2*Q);
    S = min(S, min(2*H, 4*Q));
    D = min(min(D, 2*S), min(4*H, 8*Q));

    ans = ((N-N%2)/2)*D + (N%2)*S;
    cout << ans  << endl;
    return 0;
}