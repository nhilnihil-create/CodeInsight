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


int main(void){
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    vector<int> a;
    rep(i, N){
        int t; cin >> t;
        if(t<K) a.push_back(t);
    }
    sort(a.begin(), a.end());
    N=a.size();
    vector<vector<bool>> dpl(N+5, vector<bool>(K+5, false)), dpr(N+5, vector<bool>(K+5, false));
    dpl[0][0]=true;
    rep(i, N) rep(j, K+1){
        dpl[i+1][j] = dpl[i+1][j] | dpl[i][j];
        if(j-a[i]>=0) dpl[i+1][j] = dpl[i+1][j] | dpl[i][j-a[i]];
    }
    dpr[N+1][0]=true;
    reprev(i, N) rep(j, K+1){
        dpr[i+1][j] = dpr[i+1][j] | dpr[i+2][j];
        if(j-a[i]>=0) dpr[i+1][j] = dpr[i+1][j] | dpr[i+2][j-a[i]];
    }

    int ans=0;
    repr(i, 1, N+1){
        vector<int> L, R;
        rep(j, K+1){
            if(dpl[i-1][j]) L.push_back(j);
            if(dpr[i+1][j]) R.push_back(j);
        }
        // rep(j, L.size()) cout << L[j] << ' ';
        // cout << endl;
        // rep(j, R.size()) cout << R[j] << ' ';
        // cout << endl;
        bool flg=true;
        rep(j, (int)L.size()){
            int left=L[j];
            if( lower_bound(R.begin(), R.end(), K-left) - lower_bound(R.begin(), R.end(), K-a[i-1]-left) > 0 ){
                flg=false; break;
                
            }
        }
        if(flg) ++ans;
    }
    cout << ans << endl;

    
    return 0;
}
