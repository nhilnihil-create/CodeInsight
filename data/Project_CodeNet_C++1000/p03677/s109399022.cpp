#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    vector<P> b(n);
    rep(i, n){
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b.begin(), b.end());
    int cnt = 0;
    ll d = 0;
    rep(i, n-1){
        if(a[i+1] < a[i]){
            cnt++;
            d += m - a[i] - 1;
        }
    }
    
    int idx = 0;
    int x = 1;
    ll mx = 0;
    while(x <= m){
        d += cnt;
        mx = max(mx, d);
        if(idx < n){
            while(b[idx].first <= x){
                int j = b[idx].second;
                if(j == n-1){
                    d -= (a[j] - a[j-1] + m) % m - 1;
                    cnt--;
                }else if(j > 0){
                    d -= (a[j] - a[j-1] + m) % m;
                }else{
                    d--;
                    cnt++;
                }
                idx++;
                if(idx == n)break;
            }
        }
        x++;
    }
    ll ans = 0;
    rep(i, n-1)ans += (a[i+1] - a[i] + m) % m;
    ans -= mx;
    cout << ans << endl;
}