#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod*mod;
constexpr int MAX = 100010;

bool check(int H, int W, vector<vector<int>> &a){
    lint sum=0;
    rep(i, H)rep(j, W) sum+=a[i][j];
    return sum>0;
}

int main(){
    int H, W, h, w;
    scanf("%d%d%d%d", &H, &W, &h, &w);
    if(h==1 && w==1){
        printf("No\n");
        return 0;
    }
    vector<vector<int>> a(H, vector<int>(W));
    int K=((int)1e9-1)/(h*w-1);
    int L=-K*(h*w-1)-1;
    rep(i, H)rep(j, W) a[i][j]=(i+1)%h==0 && (j+1)%w==0 ? L : K;
    if(!check(H, W, a)) printf("No\n");
    else{
        printf("Yes\n");
        rep(i, H){
            rep(j, W) printf("%d ", a[i][j]);
            printf("\n");
        }
    }
}