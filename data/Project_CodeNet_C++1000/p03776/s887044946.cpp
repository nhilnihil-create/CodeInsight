#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

ll c[51][51];
int main(){
    int N, A, B; cin >> N >> A >> B;
    
    vector<ll> v(N);
    rep(i,N) cin >> v[i];

    sort(v.rbegin(), v.rend());

    // パスカルの三角形により二項係数を求める
    c[0][0] = 1;
    for (int i = 1; i <= 50; i++){
        for (int j = 0; j <= i; j++){
            c[i][j] += c[i-1][j];
            if (j > 0) c[i][j] += c[i-1][j-1];
        }
    }

    // 平均値の最大を求める
    ll sum = 0;
    rep(i,A){
        sum += v[i];
    }
    double ave = (double)sum/A;

    // 降順でA個目の価値と同じ数字の数を求める
    int ath_count = 0;
    rep(i,N){
        if (v[i] == v[A-1]) ath_count++;
    }

    ll ans = 0;
    // 降順でA個目まですべて同じ数値の場合
    if (v[0] == v[A-1]){
        for (int i = A; i <= B;i++){
            if (v[0] != v[i-1]) break;
            ans += c[ath_count][i];
        }
    }
    else{
        // A個目まででA番目と同じ数字の数を求める
        int ath_count_till_A = 0;
        rep(i,A) {
            if (v[i] == v[A-1]) ath_count_till_A++;       
        }
        ans = c[ath_count][ath_count_till_A];
    }
    cout << fixed << setprecision(20) << ave << endl;
    cout << ans << endl;
}