#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, T;
    cin >> N >> T;
    vector<ll> t(N);
    for(int i=0; i<N; i++) cin >> t[i];

    ll max_time = 0;
    ll total_time = 0;

    for(int i=0; i<N; i++) {
        if(max_time >= t[i]) {
            total_time += t[i]+T-max_time;
        }
        else {
            total_time += T;
        }
        max_time = t[i]+T;
    }
    cout << total_time << endl;
}