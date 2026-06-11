#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <random>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

ll y[10000005];

int main() {
    int w,h,n; cin >> w >> h >> n;
    vector<int> x(n),y(n),a(n);
    rep(i,n) cin >> x[i] >> y[i] >> a[i];

    int c[h][w];
    rep(i,h)rep(j,w) c[i][j] = 0;

    rep(i,n){
        if(a[i] == 1){
            rep(j,h) rep(k,x[i]) c[j][k] = 1;
        }else if(a[i] == 2){
            rep(j,h) for(int k = x[i]; k < w; k++) c[j][k] = 1;
        }else if(a[i] == 3){
            rep(j,y[i]) rep(k,w) c[j][k] = 1;
        }else{
            for(int j = y[i]; j < h; j++)rep(k,w) c[j][k] = 1;
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) if(c[i][j] == 0) ans++;
    cout << ans << endl;
}
