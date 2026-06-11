#include <bits/stdc++.h>

// #define DEBUG
#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int H, W, h, w;

int count_use(int i, int j){
    return min(i+1, H-i) * min(j+1, W-j);
}

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> H >> W >> h >> w;

    if(H % h == 0 && W % w == 0){
        cout << "No" << endl;
        return 0;
    }

    ll ans[H][W];
    ll a = (10e8-1)/(h*w-1);
    rep(H){
        repp(j, W){
            if((i+1)%h == 0 && (j+1)%w == 0){
                ans[i][j] = -a*(h*w-1)-1;
            }else{
                ans[i][j] = a;
            }
        }
    }

    cout << "Yes" << endl;
    rep(H){
        repp(j, W) cout << ans[i][j] << " ";
        cout << endl;
    }
}