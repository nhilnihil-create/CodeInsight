#include <bits/stdc++.h>

#define LL long long
#define VI vector<int>
#define VB vector<bool>
#define VL vector<long long>
#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define EPS 1e-14

const std::string YES = "YES";
const std::string Yes = "Yes";
const std::string NO = "NO";
const std::string No = "No";

using namespace std;

template <class T> int find_index(T x, const std::vector<T> &v) {
    auto it = std::find(v.begin(), v.end(), x);
    if (it != v.end()) { return (int)std::distance(v.begin(), it); }
    return -1;
}
template<class T> T ceil(T a, T b) { return (a + b - 1) / b; }

template <class T> void print(T x) {
    std::cout << x << std::endl;
}
// 4近傍（右, 下, 左, 上）
const vector<int> dy = { 0, -1, 0, 1 };
const vector<int> dx = { 1, 0, -1, 0 };


class Imos {
public:
    const unsigned int N;
    vector<long long> dp;
    Imos(unsigned int N) : N(N) {
        dp = vector<long long>(N + 10);
    }

    // [a, b]にkを加える
    void add(int a, int b, int k) {
        dp[a] += k;
        dp[b + 1] -= k;
    }

    // 円環状で[a, b]にk加える
    void add_circle(int a, int b, int k) {
        if (a <= b) {
            add(a, b, k);
        }
        else {
            add(b, N, k);
            add(0, b, k);
        }
    }

    void build() {
        for (int i = 0; i < dp.size() - 1; ++i) {
            dp[i + 1] += dp[i];
        }
    }

    void print() {
        for (int i = 0; i < dp.size(); ++i) {
            if (i != 0) { cout << " "; }
            cout << dp[i];
        }
        cout << endl;
    }

};


void solve(long long m, vector<long long> &a){

    Imos imos1(m), imos2(m);
    LL naive = 0;
    FOR(i, 0, a.size() - 1) {
        int b = a[i];
        int e = a[i + 1];

        if (b <= e){
            // [b + 1, e]
            imos1.add(b + 1, e, -(b + 1));
            imos2.add(b + 1, e, 1);

            naive += e - b;
        }
        else{
            imos1.add(b + 1, m - 1, -(b + 1));
            imos1.add(0, e, m - b - 1);

            imos2.add(b + 1, m - 1, 1);
            imos2.add(0, e, 1);

            naive += m - (b - e);
        }
    }
    imos1.build();
    imos2.build();

    LL ans = LONG_LONG_MAX;
    FOR(i, 0, m) {
        ans = min(ans, naive - (imos1.dp[i] + i * imos2.dp[i]));
    }

    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long m;
    long long n;
    cin >> n >> m;
    vector<long long> a(n);

    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    solve(m, a);
    return 0;
}

