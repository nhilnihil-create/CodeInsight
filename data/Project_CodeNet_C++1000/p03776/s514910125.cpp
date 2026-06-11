#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr ll MOD = 67280421310721;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
long long com[51][51];
ll calcComb(ll a, ll b) { return com[a][b]; }

//大きい順にA個えらんだとき，それらの値がすべて同じの時V個数からA~Bえらぶ
//そうでないとき最小の値をvとしてvの値を持つ数値がV個,
// A個の中からvの値をもつものがa個あったとするとV個からa個選ぶ
int main() {
    int A, B, N;
    cin >> N >> A >> B;
    // A個以上B個以下
    com[0][0] = 1;
    for(int i = 1; i < 51; ++i) {
        for(int j = 0; j <= i; ++j) {
            //新しく追加されたのを選ばない
            com[i][j] += com[i - 1][j];
            if(j > 0) {
                //新しく追加されたのを選ぶ
                com[i][j] += com[i - 1][j - 1];
            }
        }
    }
    vector<ll> v(N);
    map<ll, int> all_cnt;
    REP(i, N) {
        cin >> v[i];
        all_cnt[v[i]]++;
    }
    sort(v.begin(), v.end());
    double s = 0;
    map<ll, int> cnt;
    REP(i, A) {
        s += (double)v[N - i - 1];
        cnt[v[N - i - 1]]++;
    }

    cout << fixed << setprecision(10) << s / (double)A << endl;
    int c = cnt[v[N - A]];
    if(c == A) {
        ll ans = 0;
        for(int i = A; i <= B; i++) {
            ll diff = calcComb(all_cnt[v[N - A]], i);
            ans += diff;
            // cout << diff << "comb" << all_cnt[v[N - A]] << ";" << i << endl;
        }
        // cout << "hoge" << endl;
        cout << ans << endl;
        return 0;
    }
    if(c == 1) {
        cout << all_cnt[v[N - A]] << endl;
    } else {
        cout << calcComb(all_cnt[v[N - A]], c) << endl;
    }
    return 0;
}