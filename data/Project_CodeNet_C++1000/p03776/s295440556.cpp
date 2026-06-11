#include <bits/stdc++.h>
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
    詰まった時に、別の分野の問題として考え直す（これdpでは？、グラフとしてみればいいのでは？）
    多くの問題はパターンマッチだが、パターンに落とし込むまでが難しく、そのための訓練としてわからない問題をあれこれ色々な角度から考察してみるのではないか
    cin.tie(0);
    ios::sync_with_stdio(false);<- これら、printfとかと併用しない方が良さそう

*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <--------------------------------------------> */



// パスカルの三角形を使った実装
ll C[55][55]; // C[n][k] -> nCk

void comb_table(int N){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i) C[i][j] = 1LL;
            else C[i][j] = (C[i-1][j-1]+C[i-1][j]);
        }
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    comb_table(50);
    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n);
    ll maxv=0;
    rep(i, n) { cin >> v[i]; chmax(maxv, v[i]); }

    sort(v.rbegin(), v.rend());
    double ans=0;
    rep(i, a) ans+=v[i];
    ans/=(double)a;

    if(maxv==v[a-1]){
        int cnt=0;
        ll res=0;
        rep(i, n) if(v[i]==maxv) ++cnt;
        repr(i, a, min(b, cnt)+1) res+=C[cnt][i];
        cout << setprecision(10);
        cout << ans << endl;
        cout << res << endl;
    }
    else{
        int cnt1=0, cnt2=0;
        rep(i, n) if(v[i]==v[a-1]) {
            ++cnt1;
            if(i<a) ++cnt2;
        }
        ll res=C[cnt1][cnt2];
        cout << setprecision(10);
        cout << ans << endl;
        cout << res << endl;
    }

    return 0;
}
