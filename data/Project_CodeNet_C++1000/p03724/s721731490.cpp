#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N, M; cin >> N >> M;
    ll ans = 0;
    vector<ll> E(N+1);
    for(int i = 0; i < M; i++){
        ll a, b; cin >> a >> b;
        if(a == 1) E[b]++;
        else if(b == 1) E[a]++;
        else {E[a]++; E[b]++;}
    }

    for(int i = 2; i < N+1; i++){
        if(E[i]%2 != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

}
