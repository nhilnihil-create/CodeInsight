#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
 
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,K;
    cin >> N >> K;
    vector<ll> a(N),S1(N+1),S2(N+1);
    rep(i,N){
        cin >> a[i];
        S1[i+1] = S1[i] + a[i];
        S2[i+1] = S2[i] + (a[i]>=0?a[i]:0);
    }
    ll ans = 0;
    for(int i= 0;i+K<=N;i++){
        int left = i, right = i + K;
        long long t = (S2[left] - S2[0]) + max(0LL, S1[right] - S1[left]) + (S2[N] - S2[right]);
        ans = max(ans,t);
    }
    cout << ans << endl;
}