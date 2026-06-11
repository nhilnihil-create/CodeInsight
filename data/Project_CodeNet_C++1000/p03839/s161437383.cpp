#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using namespace std;
using LL = long long;
// 型に合わせた値 2倍してもオーバーフローしないようにする
// const int INF = 1e9;
const LL INF = 1e17;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];

    vector<LL> v(N+1, 0);    // 累積和
    for(int i=0; i<N; i++) v[i+1] = v[i]+a[i];
    vector<LL> w(N+1, 0);    // 正の値のみの累積和
    for(int i=0; i<N; i++) w[i+1] = w[i]+max(a[i], 0);

    LL ans = -INF;
    for(int i=0; i+K<=N; i++){
        LL tmp = w[N];
        // Kマスを白or黒に塗る
        tmp += max(v[i+K]-v[i], 0LL);
        tmp -= w[i+K]-w[i];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}