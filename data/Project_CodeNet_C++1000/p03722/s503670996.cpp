// 解き直し.
// https://img.atcoder.jp/abc061/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const LL INF = 1LL << 50;
const int NMAX = 1000;
const int MMAX = 2000;
int a[MMAX], b[MMAX];
LL c[MMAX], dist[NMAX];
bool negative[NMAX];

int main(){

    // 1. 入力情報.
    int N, M;
    scanf("%d %d", &N, &M);
    rep(i, M){
        scanf("%d %d %lld", &a[i], &b[i], &c[i]);
        c[i] *= -1;
    }
    
    // 2. Bellman Ford法.
    rep(i, N) dist[i] = INF;
    
    // 3. コストの小さい経路を確認.
    dist[0] = 0;
    rep(_, N){
        rep(i, M){
            if(dist[a[i] - 1] == INF) continue;
            dist[b[i] - 1] = min(dist[b[i] - 1], dist[a[i] - 1] + c[i]);
        }
    }
    
    // 4. 閉路チェック.
    LL ans = dist[N - 1];
    rep(_, N){
        rep(i, M){
            if(dist[a[i] - 1] == INF) continue;
            LL d = dist[a[i] - 1] + c[i];
            if(dist[b[i] - 1] > d){
                dist[b[i] - 1] = d;
                negative[b[i] - 1] = true;
            }
            
            if(negative[a[i] - 1]) negative[b[i] - 1] = true;
        }
    }
    
    // 5. 出力.
    if(negative[N - 1]) printf("%s\n", "inf");
    else                printf("%lld\n", -ans);
    return 0;

}