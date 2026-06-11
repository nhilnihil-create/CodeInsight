#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> V(200000);

    for(int i=0; i<N; i++) {
        ll a, b;
        cin >> a >> b;
        V[a] += b;
    }

    ll total = 0;
    for(int i=0; i<V.size(); i++) {
        total += V[i];
        if(total >= K) {
            cout << i << endl;
            return 0;
        }
    }
}