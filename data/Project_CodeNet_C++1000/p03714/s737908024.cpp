#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
const ll INF = 5e15;
int main(){
    vector<priority_queue<ll, vector<ll>, function<bool(ll, ll)>>> v = {
        priority_queue<ll, vector<ll>, function<bool(ll, ll)>>([](const ll &a, const ll &b){return a > b;}),
        priority_queue<ll, vector<ll>, function<bool(ll, ll)>>([](const ll &a, const ll &b){return a < b;})
    };
    ll N;
    cin >> N;
    vector<ll> A(3 * N);
    for(auto &a : A) cin >> a;
    vector<vector<ll>> val(2, vector<ll>(N + 1));
    for(ll i = 0; i <= 1; i++){
        ll sum = 0;
        for(ll j = 0; j < N; j++){
            sum += A[j];
            v[i].push(A[j]);
        }
        val[i][0] = sum;
        for(ll j = 0; j < N; j++){
            v[i].push(A[N + j]);
            sum += A[N + j];
            sum -= v[i].top();
            v[i].pop();
            val[i][j + 1] = sum;
        }
        reverse(A.begin(), A.end());
    }
    reverse(val[1].begin(), val[1].end());
    ll ans = -INF;
    for(ll i = 0; i < N + 1; i++) ans = max(ans, val[0][i] - val[1][i]);
    cout << ans << endl;
    return 0;
}
