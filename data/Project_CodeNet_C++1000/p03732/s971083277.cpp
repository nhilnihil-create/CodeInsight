#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}


signed main() {
    int N, W;
    cin >> N >> W;

    vi w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    //バッグがある重さのときの、価値の最大値を更新していくマップ
    map<int, int> dp;
    dp[0] = 0;

    int res = 0;

    //この問題ではw[0]からw[0]+3までの重さの物しか存在しないため、
    //重さの総和が同じになる組み合わせが多く存在するはずである。
    //したがって、全ての物について入れるか、入れないかの２通りを試しても、
    //重さの総和の状態数はさほど大きくならない。
    //よって、i-1番目までの全ての物についてバッグに入れる/入れないを試していった際に
    //ありうるすべての重さの総和に対して、i番目の物を入れる/入れないを試していくことができる。

    //物の重さの制約がもう少しでも緩ければ、この方法は用いることが出来ないと考えられる。
    rep(i, N) {
        auto tmp = dp;

        //int cnt = 0;
        for(auto p: tmp) {
            auto x = p.first + w[i];
            auto y = p.second + v[i];
            if(x <= W) res = max(res, dp[x]=max(dp[x], y));
            //cnt++;
        }
        //cout << cnt << endl;
    }

    cout << res << endl;
    
    return 0;
}