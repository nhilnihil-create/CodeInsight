#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N, M;
    cin >> N >> M;
    int l[N], r[N];
    rep(i, N) cin >> l[i] >> r[i];
    int ans[M+1], query[M+2];
    fill(ans, ans+M+1, 0);
    fill(query, query+M+2, 0);
    rep(i, N){
        //未チェックの中で最小のもの
        int j = 1;
        //m:=チェックした中で最小のもの
        int m = M+1;
        while(j < m){
            int L = (l[i]+j-1)/j, R = r[i]/j;
            if(L <= R) ans[j]++;
            chmin(R, m-1);
            chmax(L, j+1);
            if(R >= L) query[L]++, query[R+1]--;
            m = L, j++;
        }
    }
    int sum = 0;
    rep2(i, 1, M){
        sum += query[i];
        cout << ans[i]+sum << endl;
    }
}