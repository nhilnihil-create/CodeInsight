#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll N, L, T;
    cin >> N >> L >> T;
    vector<ll> ans;
    pair<ll, ll> a[N];
    for(ll i = 0; i < N; i++) cin >> a[i].first >> a[i].second;
    ll index = 0;
    for(ll i = 1; i < N; i++){
        if(a[i].second == a[0].second) continue;
        ll dist = (ll)abs(a[i].first - a[0].first);
        if(a[0].second == 2) dist = L - dist;
        ll add = (2 * T - dist) / L + (2 * T >= dist);
        index += (a[0].second == 1 ? 1 : -1) * add;
    }
    if(index < 0) index += ((-index) / N + 1) * N;
    index %= N;
    for(ll i = 0; i < N; i++){
        if(a[i].second == 1){
            ans.push_back((a[i].first + T) % L);
        }else{
            ll po = a[i].first - T;
            if(po < 0) po += ((-po) / L + 1) * L;
            ans.push_back(po % L);
        }
    }
    ll pos = ans[0];
    ll here;
    sort(ans.begin(), ans.end());
    if(a[0].second == 1){
        for(ll i = N -  1; i >= 0; i--){
            if(ans[i] == pos){
                here = i;
                break;
            }
        }
    }else{
        for(ll i = 0; i < N; i++){
            if(ans[i] == pos){
                here = i;
                break;
            }
        }
    }
    vector<ll> output(N);
    for(ll i = 0; i < N; i++) output[(index + i) % N] = ans[(here + i) % N];
    for(ll out : output) cout << out << endl;
    return 0;
}
