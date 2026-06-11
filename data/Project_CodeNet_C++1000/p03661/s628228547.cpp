#include <bits/stdc++.h>
#define INF 1e+9
#define debug(x) cerr << #x << ": " << x << "\n";
using namespace std;
using ll = long long;
using P = pair<int, int>;

int a[200000];

int main(void){
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];

    ll x = a[0], y = accumulate(a + 1, a + N, 0LL);
    ll res = abs(x - y);
    for(int i = 1; i < N - 1; i++){
        x += a[i]; y -= a[i];
        res = min(res, abs(x - y));
    }

    cout << res << '\n';
    return 0;
}