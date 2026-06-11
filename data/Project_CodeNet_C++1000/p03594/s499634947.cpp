#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<int, lint> pil;
typedef pair<lint, int> pli;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 100010;

int main(){
    int h, w, d;
    scanf("%d%d%d", &h, &w, &d);

    string s = "RGBY";
    int K = h+w;
    char grid[K+1][K+1];
    for(int i=0; i<=K; i+=d)for(int j=0; j<=K; j+=d){
        char c = s[i/d%2*2 + j/d%2];
        for(int x=0; x<d && i+x<=K; ++x)for(int y=0; y<d && j+y<=K; ++y){
            grid[i+x][j+y] = c;
        }
    }

    rep(i, h){
        rep(j, w) printf("%c", grid[i+j][i-j+w]);
        printf("\n");
    }
}