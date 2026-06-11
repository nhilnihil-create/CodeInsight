#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N; cin >> N;
    ll A[3*N]; rep(i, 3*N) cin >> A[i];
    priority_queue<ll, vector<ll>, greater<ll>> pq_front;
    priority_queue<ll> pq_back;
    for(int i = 0; i < N; i++) pq_front.push(A[i]);
    for(int i = 3*N-1; i >= 2*N; i--) pq_back.push(A[i]);

    ll sum_front = 0, sum_back = 0;
    rep(i, N){
        sum_front += A[i];
        sum_back += A[3*N -1 - i];
    }
    ll zenhan[N+1], kouhan[N+1];
    zenhan[0] = sum_front; kouhan[N] = sum_back;
    for(int i = N; i < 2*N; i++){
        ll dif = A[i] - pq_front.top();
        if(dif > 0){
            sum_front += dif;
            pq_front.pop();
            pq_front.push(A[i]);
        }
        zenhan[i - (N-1)] = sum_front;
    }
    for(int i = 2*N-1; i >= N; i--){
        ll dif = A[i] - pq_back.top();
        if(dif < 0){
            sum_back += dif;
            pq_back.pop();
            pq_back.push(A[i]);
        }
        kouhan[i - N] = sum_back;
    }
    ll ans = zenhan[N]-kouhan[N];
    rep(i, N) ans = max(ans, zenhan[i]-kouhan[i]);
    cout << ans << endl;

    return 0;
}