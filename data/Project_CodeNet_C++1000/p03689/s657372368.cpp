#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int H, W, h, w;
int ans[510][510];
int mx = 1e9 - 1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> W >> h >> w;
    if(h == 1 && w == 1){
        cout << "No" << endl;
        return 0;
    }
    mx /= (h * w - 1);
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            ans[i][j] = mx;
        }
    }
    for(int i = h; i <= H; i += h){
        for(int j = w; j <= W; j += w){
            ans[i][j] = -(mx * (h * w - 1) + 1);
        }
    }
    ll sum = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            sum += ans[i][j];
        }
    }
    if(sum <= 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                cout << ans[i][j] << (j != W ? " " : "\n");
            }
        }
    }
    return 0;
}