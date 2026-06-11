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
#include <cassert>
#include <numeric>
#define ll long long int
#define LL unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main() {
    int h, w; cin >> h >> w;
    char c[h][w], ans[2*h][w];
    rep(i,h) rep(j,w) cin >> c[i][j];

    rep(i,h){
        rep(j,w){
            ans[i*2][j] = c[i][j];
            ans[i*2+1][j] = c[i][j];
        }
    }
    rep(i,2*h) {
        rep(j,w){
            cout << ans[i][j];
        }cout << endl;
    }
}
