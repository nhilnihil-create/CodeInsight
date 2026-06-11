#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;

    ll A[N];
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    ll cost_min = 1e9;

    for(ll i = -100; i <= 100; i++){
        ll cost = 0;
        for(ll j = 0; j < N; j++){
            cost += (A[j] - i) * (A[j] - i);
        }
        if(cost <= cost_min){
            cost_min = cost;
        }
    }

    cout << cost_min << endl;

    return 0;
}
