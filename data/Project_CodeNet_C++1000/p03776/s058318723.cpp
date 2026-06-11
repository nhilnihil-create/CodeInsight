#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

const int MAX_C = 51;
long long Com[MAX_C][MAX_C];

void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]);
        }
    }
}

int main(){
    int N,A,B;cin >> N >> A >> B;
    vector<LL> v(N);
    rep(i,N)cin >> v[i];
    vector<int> ct(N+1,0);
    vector<int> rui(N+1,0);
    sort(rall(v));

    // 配列vに格納された数字が大きい順に何種類が何個あるかチェック
    int tmp = 1;
    ct[1] = 1;
    for(int i = 1;i < N;++i){
        if(v[i] != v[i-1])tmp++;
        ct[tmp]++;
    }
    rui[0] = 0;
    for(int i = 1;i <= N;++i){
        rui[i] = rui[i-1] + ct[i];
    }

    // 前処理
    calc_com();

    // 累積和から必要なindexを得る
    int ind = 0;
    double mean = 0;
    LL ans = 0;
    if(rui[1] >= B){    // B part
        for(int i = A;i <= B;++i){
            ans += Com[rui[1]][i];
        }
        mean = v[0];
    }
    else{               // A part
        if(rui[1] >= A){    // Aの例外
            for(int i = A;i <= rui[1];++i){
                ans += Com[rui[1]][i];
            }
            mean = v[0];            
        }
        else{
            for(int i = 1;i < rui.size();++i){
                if(rui[i] >= A){
                    ind = i;
                    break;
                }
            }
            int a = rui[ind] - rui[ind - 1];
            int b = A - rui[ind - 1];
            ans = Com[a][b];
            rep(i,A)mean += (double)v[i];
            mean /= (double)A;
        }
    }

    cout << std::fixed << std::setprecision(7) << mean << endl;
    cout << ans << endl;
}