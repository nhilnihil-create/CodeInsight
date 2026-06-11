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


int main(){
    int N; cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    vector<int> counter(10000000, 0);

    rep(i,N){
        if (a[i]-1 >= 0 ) counter[a[i]-1]++;
        counter[a[i]]++;
        counter[a[i]+1]++;
    }

    int ans = 0;
    rep(i,10000000){
        ans = max(ans, counter[i]);
    }

    cout << ans << endl;


}