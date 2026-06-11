#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if(H%h == 0 && W%w == 0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
        if(W%w != 0){
            rep(i, H){
                rep(j, W){
                    if(j%w == 0) cout << 1000*(w-1)-1;
                    else cout << -1000;
                    cout << " ";
                }
                cout << endl;
            }
        }
        else{
            rep(i, H){
                rep(j, W){
                    if(i%h == 0) cout << 1000*(h-1)-1;
                    else cout << -1000;
                    cout << " ";
                }
                cout << endl;
            }
        }
    }
}