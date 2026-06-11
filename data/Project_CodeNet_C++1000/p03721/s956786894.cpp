#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, count = 0;
    ll K;
    cin >> N >> K;
    vector<ll> Z(100001);


    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        Z[a] += b;
    }
    for(int i=1; i<=100001; i++) {
        if(Z[i] >= K) {
            cout << i << endl;
            return 0;
        }
        K -= Z[i];
    }
}