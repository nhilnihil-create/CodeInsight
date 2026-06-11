#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000;
LL a[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    LL N, x;
    cin >> N >> x;
    for(int i = 0; i < N; i += 1) cin >> a[i];
    LL ans = 0;
    for(int i = 0; i < N; i += 1) ans += b[i] = a[i];
    for(int k = 1; k < N; k += 1){
        LL pans = k * x;
        for(int i = 0; i < N; i += 1) pans += b[i] = min(b[i], a[(i + N - k) % N]);
        ans = min(ans, pans);
    }
    cout << ans;
}