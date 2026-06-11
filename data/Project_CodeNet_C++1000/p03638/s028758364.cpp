#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vec<int> a(N);
    rep(i, N) cin >> a[i];

    vec<vec<int>> ans(H, vec<int>(W));
    rep(i,H)rep(j,W){

        int now = 0;
        rep(k,N) {
            if(a[k] != 0){
                now = k+1;
                --a[k];
                break;
            }
        }

        ans[i][(i%2==0?j:(W-1-j))] = now;
    }
    rep(i,H){
        rep(j,W){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
